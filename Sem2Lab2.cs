/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    16.02.2024                                    *
* Название: ООП на C#                                    * 
* https://onlinegdb.com/60qDbjhP4                        *
**********************************************************/
using System;

public class Document {
    public string DocumentName { get; set; }
    public string DocumentAuthor { get; set; }
    public string[] DocumentKeywords { get; set; }   
    public string DocumentTheme { get; set; }
    public string DocumentFilePath { get; set; }
    public virtual void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
    }
}

public class MSWordDocument : Document {
    public int MSWordDocumentPageCount { get; set; }
    public override void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
        Console.WriteLine($"Page Count: {MSWordDocumentPageCount}");
    }
}

public class PDFDocument : Document {
    public bool PDFDocumentIsSecured { get; set; }
    public override void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
        Console.WriteLine($"Is Secured: {PDFDocumentIsSecured}");
    }
}

public class MSExcelDocument : Document {
    public string MSExcelDocumentCreationDate { get; set; }
    public override void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
        Console.WriteLine($"Creation Date: {MSExcelDocumentCreationDate}");
    }
}

public class TXTDocument : Document {
    public int TXTDocumentWordCount { get; set; }
    public override void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
        Console.WriteLine($"Word Count: {TXTDocumentWordCount}");
    }
}

public class HTMLDocument : Document {
    public string[] HTMLDocumentHyperlinks { get; set; }
    public override void GetDocumentInfo() {
        Console.WriteLine($"Document: {DocumentName}");
        Console.WriteLine($"Author: {DocumentAuthor}");
        Console.WriteLine($"Keywords: {string.Join(", ", DocumentKeywords)}");
        Console.WriteLine($"Theme: {DocumentTheme}");
        Console.WriteLine($"File Path: {DocumentFilePath}");
        Console.WriteLine($"Hyperlinks: {string.Join(", ", HTMLDocumentHyperlinks)}");
    }
}

public class DocumentManager {
    private static DocumentManager instance;

    private DocumentManager() { }

    public static DocumentManager Instance {
        get {
            if (instance == null) {
                instance = new DocumentManager();
            }
            return instance;
        }
    }

    public void DisplayDocumentInfo (Document document) {
        document.GetDocumentInfo();
    }
}

class Programm {
    static void Main(string[] args) {
        DocumentManager documentManager = DocumentManager.Instance;

        MSWordDocument wordDocument = new MSWordDocument {
            DocumentName = "laba otchet",
            DocumentAuthor = "Joe Biden",
            DocumentKeywords = [ "sleep", "Sleep", "sleeping" ],
            DocumentTheme = "Programming",
            DocumentFilePath = "C:/Documents/labaotchet.docx",
            MSWordDocumentPageCount = 12
        };

        PDFDocument pdfDocument = new PDFDocument {
            DocumentName = "PDFDoc",
            DocumentAuthor = "someone",
            DocumentKeywords = [ "PDF", "Report", "Analysis" ],
            DocumentTheme = "Data Science",
            DocumentFilePath = "C:/Documents/PDFDoc.pdf",
            PDFDocumentIsSecured = true
        };


        documentManager.DisplayDocumentInfo(wordDocument);
        Console.WriteLine();
        documentManager.DisplayDocumentInfo(pdfDocument);
    }
}
