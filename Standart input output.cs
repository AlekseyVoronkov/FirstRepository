using System.Xml.Serialization;
using static TextFile;
using System.Text;

[Serializable]
public class TextFile
{
    public string FileName { get; set; }
    public string Content { get; set; }

    public void WriteText(string text)
    {
        Content += text;
    }

    public void SerializeToXml(string filePath)
    {
        XmlSerializer xmlSerializer = new XmlSerializer(typeof(TextFile));
        using (StreamWriter writer = new StreamWriter(filePath))
        {
            xmlSerializer.Serialize(writer, this);
        }
    }

    public static TextFile DeserializeFromXml(string filePath)
    {
        XmlSerializer serializer = new XmlSerializer(typeof(TextFile));
        using (StreamReader reader = new StreamReader(filePath))
        {
            return (TextFile)serializer.Deserialize(reader);
        }
    }

    public void BinarySerialization(string filePath)
    {
        using (BinaryWriter writer = new BinaryWriter(File.Open(filePath, FileMode.OpenOrCreate)))
        {
            writer.Write(FileName);
            writer.Write(Content);
        }
    }

    public void DeserializeFromBinary(string filePath)
    {
        if (File.Exists(filePath))
        {
            using (var stream = File.Open(filePath, FileMode.Open))
            {
                using (var reader = new BinaryReader(stream))
                {
                    FileName = reader.ReadString();
                    Content = reader.ReadString();
                }
            }

            Console.WriteLine("File name: " + FileName);
            Console.WriteLine("Content of file: " + Content);

        }
    }

    public string GetContent()
    {
        return Content;
    }

    public string GetName()
    {
        return FileName;
    }

    public TextFileMemento Save()
    {
        return new TextFileMemento(FileName, Content);
    }

    public void Restore(TextFileMemento memento)
    {
        Content = memento.GetSavedContent();
    }

    public class TextFileMemento : TextFile
    {
        public TextFileMemento(string mementoName, string mementoContent)
        {
            Content = mementoContent;
            FileName = mementoName;
        }

        public string GetSavedContent()
        {
            return Content;
        }
    }
}

class TextFileHistory
{
    private List<TextFileMemento> history = new List<TextFileMemento>();

    public void Save(TextFileMemento memento)
    {
        history.Add(memento);
    }

    public TextFileMemento GetLastSavedState()
    {
        if (history.Count > 0)
        {
            var lastIndex = history.Count - 1;
            var lastMemento = history[lastIndex];
            history.RemoveAt(lastIndex);
            return lastMemento;
        }

        return null;
    }
}

public class TextFileSearch
{
    public void SearchFilesByKeyword()
    {
        Console.WriteLine("Type a number of keywords:");

        int numberOfKeywords = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Type your directory path: ");

        string directoryPath = $"{Convert.ToString(Console.ReadLine())}";
        string[] keywords;
        keywords = new string[numberOfKeywords];

        for (int userKeywordInput = 0; userKeywordInput < numberOfKeywords; ++userKeywordInput)
        {
            Console.WriteLine($"Type in your keyword №{userKeywordInput + 1}");
            keywords[userKeywordInput] = Convert.ToString(Console.ReadLine());
        }

        Dictionary<string, List<string>> index = new Dictionary<string, List<string>>();

        foreach (string indexatingFile in Directory.GetFiles(directoryPath, "*.txt"))
        {
            string content = File.ReadAllText(indexatingFile);

            foreach (string keyword in keywords)
            {
                if (content.Contains(keyword))
                {
                    if (!index.ContainsKey(keyword))
                    {
                        index[keyword] = new List<string>();
                    }

                    index[keyword].Add(indexatingFile);
                }
            }
        }

        foreach (var keyValuePair in index)
        {
            Console.WriteLine($"Keyword: {keyValuePair.Key}");

            foreach (var indexatingFile in keyValuePair.Value)
            {
                Console.WriteLine($"\t{indexatingFile}");
            }
        }
    }
}

class Program
{
    static void Main()
    {
        bool isProgramRunning = true;

        while (isProgramRunning)
        {
            TextFileHistory history = new TextFileHistory();

            Console.WriteLine("What do you want to do?");
            Console.WriteLine("1 - Text File Editor");
            Console.WriteLine("2 - Index text files in a specified directory based on given keywords");
            Console.WriteLine("3 - Close this app");

            int userChoice = Convert.ToInt32(Console.ReadLine());

            if (userChoice != 1 && userChoice != 2 && userChoice != 3)
            {
                Console.WriteLine("I'm pretty sure that this was neither 1 nor 2. Shame on you.");
            }

            if (userChoice == 1)
            {
                TextFile textFileForEdit = new TextFile { FileName = "", Content = "" };

                Console.WriteLine();
                Console.WriteLine("Welcome to the Text File Editor!");
                Console.WriteLine("You need to type in name of your file");

                textFileForEdit.FileName = Console.ReadLine();

                Console.WriteLine("//List of commands//");
                Console.WriteLine("Enter your text (type 'SaveFile' to... Save your file");
                Console.WriteLine("Type 'Undo' to open last saved version of the file");
                Console.WriteLine("Type 'Imdonewithit' to close text editor");

                bool textRedactorLoop = true;
                while (textRedactorLoop)
                {
                    string input = Console.ReadLine();

                    if (input != "SaveFile" && input != "Undo" && input != "imdonewithit")
                    {
                        textFileForEdit.WriteText(input);
                    }

                    if (input == "SaveFile")
                    {
                        history.Save(textFileForEdit.Save());
                        using (FileStream filestream = new FileStream(textFileForEdit.GetName(), FileMode.Create))
                        {
                            byte[] buffer = Encoding.Default.GetBytes(textFileForEdit.GetContent());
                            filestream.WriteAsync(buffer, 0, buffer.Length);
                        }
                        Console.WriteLine("Saved!\n");
                    }

                    if (input == "Undo")
                    {
                        textFileForEdit.Restore(history.GetLastSavedState());
                        Console.WriteLine("//This is your last saved file//");
                        Console.WriteLine(textFileForEdit.GetContent());
                    }

                    if (input == "Imdonewithit")
                    {
                        textRedactorLoop = false;
                    }
                }
            }

            if (userChoice == 2)
            {
                bool indexThingLoop = true;
                string endSearchOrNo;

                while (indexThingLoop)
                {
                    TextFileSearch fileSearch = new TextFileSearch();
                    fileSearch.SearchFilesByKeyword();

                    Console.WriteLine("Search again? y/n");
                    endSearchOrNo = Console.ReadLine();

                    if (endSearchOrNo != "y" && endSearchOrNo != "n")
                    {
                        Console.WriteLine("you must type in y or n. Try again: ");
                        endSearchOrNo = Console.ReadLine();

                    }
                    else if (endSearchOrNo == "n")
                    {
                        indexThingLoop = false;
                    }
                }
            }

            if (userChoice == 3)
            {
                isProgramRunning = false;
            }
        }
    }
}
