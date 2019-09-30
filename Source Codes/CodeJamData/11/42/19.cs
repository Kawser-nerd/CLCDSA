using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{
    class Pair
    {
        public int start, end;
        public Pair(int start, int end)
        {
            this.start = start;
            this.end = end;
        }
        public Pair()
        {

        }

    }
    int D, h, w;
    double eps = 1e-10;
    int[,] b;
    void solve()
    {
        h = nextInt();
        w = nextInt();
        b = new int[h, w];
        D = nextInt();
        for (int i = 0; i < h; i++)
        {
            string s = nextString();
            for (int j = 0; j < w; j++)
                b[i, j] = s[j] - '0';
        }
        string res="IMPOSSIBLE";
        for (int K = Math.Min(h, w); K >= 3; K--)
        {
            bool any=false;
            for(int r=0;r+K<=h;r++)
                for (int c = 0; c + K <= w; c++)
                {
                    if (ok(r, c, K, b))
                    {
                        any = true;
                    }
                }
            if (any)
            {
                res = "" + K;
                break;
            }
        }
        println(res);
    }

    private bool ok(int r, int c,int K, int[,] b)
    {
        double C = c + K / 2.0;
        double R = r + K / 2.0;
        double cenR = 0;
        double cenC=0;
        for(int i=0;i<K;i++)
            for (int j = 0; j < K; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0 && j == K-1)
                    continue;
                if (i == K-1 && j == 0)
                    continue;
                if (i == K - 1 && j == K - 1)
                    continue;
                int m = b[i + r, j + c] + D;
                cenR += (R - (r + i+1.0/2)) * m;
                cenC += (C - (c + j+1.0/2)) * m;
            }
        if (Math.Abs(cenR) < eps && Math.Abs(cenC) < eps)
            return true;
        return false;
    }

    ///////////

    void read()
    {
        int testCases = int.Parse(nextLine());

        for (int test = 1; test <= testCases; test++)
        {
            print("Case #" + test + ": ");
            solve();

        }
        close();
        Console.WriteLine("Press Enetr");
        Console.ReadLine();

    }
    private void println(int[] ar)
    {
        for (int i = 0; i < ar.Length; i++)
        {
            if (i == ar.Length - 1)
                println(ar[i]);
            else
                print(ar[i] + " ");
        }
    }
    private void println(int[] ar, bool add)
    {
        int A = 0;
        if (add)
            A++;
        for (int i = 0; i < ar.Length; i++)
        {
            if (i == ar.Length - 1)
                println(ar[i] + A);
            else
                print((ar[i] + A) + " ");
        }
    }
    private void println(string Stringst)
    {
        sw.WriteLine(Stringst);
        Console.WriteLine(Stringst);
    }
    private void println(int Intnum)
    {
        sw.WriteLine(Intnum);
        Console.WriteLine(Intnum);
    }
    private void println(long Longnum)
    {
        sw.WriteLine(Longnum);
        Console.WriteLine(Longnum);
    }
    private void println(double Doublenum)
    {
        sw.WriteLine(Doublenum);
        Console.WriteLine(Doublenum);
    }

    private void print(string Stringst)
    {
        sw.Write(Stringst);
        Console.Write(Stringst);
    }
    private void print(int Intnum)
    {
        sw.Write(Intnum);
        Console.Write(Intnum);
    }
    private void print(long Longnum)
    {
        sw.Write(Longnum);
        Console.Write(Longnum);
    }
    private void print(double Doublenum)
    {
        sw.Write(Doublenum);
        Console.Write(Doublenum);
    }
    private void close()
    {
        sw.Close();
        sr.Close();
    }
    StreamWriter sw = new StreamWriter("output.txt");
    StreamReader sr = new StreamReader("input.txt");
    string[] inputLine = new string[0];
    int inputInd = 0;
    string nextLine()
    {
        return sr.ReadLine();
    }
    void readInput()
    {
        if (inputInd != inputLine.Length)
            throw new Exception();
        inputInd = 0;
        inputLine = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        if (inputLine.Length == 0)
            readInput();
    }
    int nextInt()
    {
        return int.Parse(nextString());
    }
    long nextLong()
    {
        return long.Parse(nextString());
    }
    double nextDouble()
    {
        return double.Parse(nextString());
    }
    string nextString()
    {
        if (inputInd == inputLine.Length)
            readInput();
        return inputLine[inputInd++];
    }
    static void Main(string[] args)
    {
        new Program().read();
    }
}
