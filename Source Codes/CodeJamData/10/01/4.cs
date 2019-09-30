using System;
using System.IO;
using System.Text;

#region Helper Classes
class Scanner : System.IO.StringReader
{
    string currentWord;

    public Scanner(string source)
        : base(source)
    {
        readNextWord();
    }

    private void readNextWord()
    {
        System.Text.StringBuilder sb = new StringBuilder();
        char nextChar;
        int next;
        do
        {
            next = this.Read();
            if (next < 0)
                break;
            nextChar = (char)next;
            if (char.IsWhiteSpace(nextChar))
                break;
            sb.Append(nextChar);
        } while (true);
        while ((this.Peek() >= 0) && (char.IsWhiteSpace((char)this.Peek())))
            this.Read();
        if (sb.Length > 0)
            currentWord = sb.ToString();
        else
            currentWord = null;
    }

    public bool hasNextInt()
    {
        if (currentWord == null)
            return false;
        int dummy;
        return int.TryParse(currentWord, out dummy);
    }

    public int nextInt()
    {
        try
        {
            return int.Parse(currentWord);
        }
        finally
        {
            readNextWord();
        }
    }

    public bool hasNextDouble()
    {
        if (currentWord == null)
            return false;
        double dummy;
        return double.TryParse(currentWord, out dummy);
    }

    public string next()
    {
        try
        {
            return currentWord;
        }
        finally
        {
            readNextWord();
        }
    }

    public double nextDouble()
    {
        try
        {
            return double.Parse(currentWord);
        }
        finally
        {
            readNextWord();
        }
    }

    public bool hasNext()
    {
        return currentWord != null;
    }
}

#endregion

public class A
{
    private static void Main()
    {
        //StreamReader reader = new StreamReader("inp.txt");
        //StreamWriter writer = new StreamWriter("out.txt");

        //StreamReader reader = new StreamReader("A-small-attempt0.in");
        //StreamWriter writer = new StreamWriter("A-small-attempt0.out");

        //StreamReader reader = new StreamReader("A-small-attempt1.in");
        //StreamWriter writer = new StreamWriter("A-small-attempt1.out");

        StreamReader reader = new StreamReader("A-large.in");
        StreamWriter writer = new StreamWriter("A-large.out");

        Scanner scanner = new Scanner(reader.ReadToEnd());

        int ct = scanner.nextInt();
        for (int t = 1; t <= ct; t++)
        {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            string ans = ((k + 1) % (1 << n) == 0) ? "ON" : "OFF";
            writer.WriteLine("Case #" + t + ": " + ans);
        }

        scanner.Close();
        reader.Close();
        writer.Close();
    }
}
