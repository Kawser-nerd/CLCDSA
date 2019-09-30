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

public class B
{
    private static readonly BigInteger b0 = new BigInteger("0", 10);

    private static BigInteger CalcGCD(BigInteger x, BigInteger y)
    {
        return (x == b0) ? y : CalcGCD(y % x, x);
    }

    private static void Main()
    {
        //StreamReader reader = new StreamReader("inp.txt");
        //StreamWriter writer = new StreamWriter("out.txt");

        //StreamReader reader = new StreamReader("B-small-attempt0.in");
        //StreamWriter writer = new StreamWriter("B-small-attempt0.out");

        //StreamReader reader = new StreamReader("B-small-attempt1.in");
        //StreamWriter writer = new StreamWriter("B-small-attempt1.out");

        StreamReader reader = new StreamReader("B-large.in");
        StreamWriter writer = new StreamWriter("B-large.out");

        Scanner scanner = new Scanner(reader.ReadToEnd());

        int ct = scanner.nextInt();

        for (int t = 1; t <= ct; t++)
        {
            BigInteger[] time = new BigInteger[1000];
            BigInteger ma;
            BigInteger ans;
            int n = scanner.nextInt();
            int li = 0;
            for (int i = 0; i < n; i++)
            {
                string str = scanner.next();
                time[i] = new BigInteger(str, 10);
                if (time[i] > time[li])
                    li = i;
            }
            BigInteger T = b0;
            for (int i = 0; i < n; i++) if (i != li) T = CalcGCD(T, time[li] - time[i]);
            if (T == b0 || time[li] % T == b0) ans = b0;
            else ans = T - time[li] % T;
            writer.WriteLine("Case #" + t + ": " + ans.ToString(10));
        }

        scanner.Close();
        reader.Close();
        writer.Close();
    }
}
