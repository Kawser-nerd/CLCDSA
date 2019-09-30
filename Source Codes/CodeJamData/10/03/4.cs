using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

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

public class C
{
    private static void Main()
    {
        //StreamReader reader = new StreamReader("inp.txt");
        //StreamWriter writer = new StreamWriter("out.txt");

        //StreamReader reader = new StreamReader("C-small-attempt0.in");
        //StreamWriter writer = new StreamWriter("C-small-attempt0.out");

        //StreamReader reader = new StreamReader("C-small-attempt1.in");
        //StreamWriter writer = new StreamWriter("C-small-attempt1.out");

        StreamReader reader = new StreamReader("C-large.in");
        StreamWriter writer = new StreamWriter("C-large.out");

        Scanner scanner = new Scanner(reader.ReadToEnd());

        int ct = scanner.nextInt();
        for (int t = 1; t <= ct; t++)
        {
            int r = scanner.nextInt();
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
            long ans = 0;
            int go = 0;
            int pos = 0;
            IList<int> stop = new List<int>();
            IList<long> money = new List<long>();
            while (go < n && go < r)
                roller(ref go, ref pos, ref ans, n, k, a, stop, money);
            if (go < r)
            {
                for (int i = 0; i < go; i++)
                    if (stop[i] == pos)
                    {
                        long hasEarned = ans - money[i];
                        int remain = r - go;
                        int no = remain / (go - i);
                        ans += hasEarned * no;
                        go = (go + no * (go - i));
                        break;
                    }
            }
            while (go < r)
                roller(ref go, ref pos, ref ans, n, k, a, stop, money);
            writer.WriteLine("Case #" + t + ": " + ans);
        }

        scanner.Close();
        reader.Close();
        writer.Close();
    }

    private static void roller(ref int go, ref int pos, ref long ans, int n, int k, int[] a, IList<int> stop, IList<long> money)
    {
        stop.Add(pos);
        money.Add(ans);
        long p = 0;
        int oldPos = pos;
        for (; ; )
        {
            if (p + a[pos] > k) break;
            p += a[pos];
            pos = (pos + 1) % n;
            if (pos == oldPos) break;
        }
        ans += p;
        go++;
    }
}
