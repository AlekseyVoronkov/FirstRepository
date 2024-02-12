/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    12.02.2024                                    *
* Название: ООП на  C#                                   * 
* https://onlinegdb.com/H0ue_71tp                        *
**********************************************************/
using System;
public class Document {
    public string Name { get; set; }
    public string Author { get; set; }
    public string[] Keywords { get; set; }
    public string Theme { get; set; }
    public string FilePath { get; set; }
}

public class WordDocument : Document {
    public int PageCount { get; set; }
}

public class PdfDocument : Document {
    public bool IsProtected { get; set; }
}

public class ExcelDocument : Document {
    public int WorksheetCount { get; set; }
}

public class TxtDocument : Document {
    public int LineCount { get; set; }
}

public class HtmlDocument : Document {
    public string[] Hyperlinks { get; set; }
}

public class DocumentManager {
    private static DocumentManager instance;
    
    private DocumentManager() { }
    
    public static DocumentManager Instance {
        get {
            if (instance == null)
            {
                instance = new DocumentManager();
            }
            return instance;
        }
    }
    
    public void DisplayDocumentInformation(Document document) {
        Console.WriteLine("Document Information:");
        Console.WriteLine($"Name: {document.Name}");
        Console.WriteLine($"Author: {document.Author}");
        Console.WriteLine($"Keywords: {string.Join(", ", document.Keywords)}");
        Console.WriteLine($"Theme: {document.Theme}");
        Console.WriteLine($"File Path: {document.FilePath}");
        
        if (document is WordDocument wordDocument) {
            Console.WriteLine($"Page Count: {wordDocument.PageCount}");
        }
        else if (document is PdfDocument pdfDocument) {
            Console.WriteLine($"Is Protected: {pdfDocument.IsProtected}");
        }
        else if (document is ExcelDocument excelDocument) {
            Console.WriteLine($"Worksheet Count: {excelDocument.WorksheetCount}");
        }
        else if (document is TxtDocument txtDocument) {
            Console.WriteLine($"Line Count: {txtDocument.LineCount}");
        }
        else if (document is HtmlDocument htmlDocument) {
            Console.WriteLine($"Hyperlinks: {string.Join(", ", htmlDocument.Hyperlinks)}");
        }
    }
}

public class Program {
    public static void Main(string[] args) {
        DocumentManager documentManager = DocumentManager.Instance;
        
        // Create sample documents
        WordDocument wordDocument = new WordDocument {
            Name = "Sample Document",
            Author = "John Doe",
            Keywords = new string[] { "sample", "document", "csharp" },
            Theme = "General",
            FilePath = "path/to/word/document.docx",
            PageCount = 10
        };
        
        PdfDocument pdfDocument = new PdfDocument {
            Name = "Sample PDF",
            Author = "Jane Smith",
            Keywords = new string[] { "sample", "pdf", "csharp" },
            Theme = "General",
            FilePath = "path/to/pdf/document.pdf",
            IsProtected = true
        };
        
        // Display document information
        documentManager.DisplayDocumentInformation(wordDocument);
        documentManager.DisplayDocumentInformation(pdfDocument);
    }
}
