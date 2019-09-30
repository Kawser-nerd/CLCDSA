using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{

    string[] all;
    string order;
    int[,] value;
    int n;
    void solve()
    {

        n = nextInt();
        int m = nextInt();
        all = new string[n];
        for (int i = 0; i < n; i++)
        {
            string cur = nextString();
            all[i] = cur;
        }
        value = new int[26, n];
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < n; i++)
                for (int k = 0; k < all[i].Length; k++)
                    if (all[i][k] == (char)('a' + j))
                        value[j, i] |= 1 << k;

        for (int step = 0; step < m; step++)
        {
            order = nextString();
            int[] res = new int[] { -1, -1 };
            for (int L = 1; L <= 10; L++)
            {
                List<int> cur = new List<int>();
                for (int i = 0; i < n; i++)
                    if (all[i].Length == L)
                        cur.Add(i);
                if (cur.Count == 0)
                    continue;
                int[] num = get(cur, 0);
                if (num[0] > res[0] || (num[0] == res[0] && num[1] < res[1]))
                    res = num;
            }
            if (step == m - 1)
            {
                println(all[res[1]]);
            }
            else
                print(all[res[1]] + " ");
        }



    }

    private int[] get(List<int> cur, int p)
    {
        if (p == order.Length)
        {
            if (cur.Count != 1)
                throw new Exception();
            return new int[] { 0, cur[0] };
        }
        Dictionary<int, List<int>> d = new Dictionary<int, List<int>>();
        int any = 0;
        foreach (int x in cur)
        {
            int num = value[order[p] - 'a', x];
            if (num != 0)
                any++;
            if (!d.ContainsKey(num))
            {
                d[num] = new List<int>();
            }
            d[num].Add(x);
        }
        if (any==0)
            return get(cur, p + 1);
        int[] res = new int[] { -1, -1 };
        foreach (KeyValuePair<int, List<int>> z in d)
        {
            int[] num = get(z.Value, p + 1);
            if (z.Key == 0)
                num[0]++;
            if (num[0] > res[0] || (num[0] == res[0] && num[1] < res[1]))
                res = num;
        }
        return res;
    }



    private long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }


    ///////////

    void read()
    {

        int testCases = int.Parse(nextLine());

        for (int test = 1; test <= testCases; test++)
        {
            sw.Write("Case #" + test + ": ");
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
    }
    private void println(int Intnum)
    {
        sw.WriteLine(Intnum);
    }
    private void println(long Longnum)
    {
        sw.WriteLine(Longnum);
    }
    private void println(double Doublenum)
    {
        sw.WriteLine(Doublenum);
    }

    private void print(string Stringst)
    {
        sw.Write(Stringst);
    }
    private void print(int Intnum)
    {
        sw.Write(Intnum);
    }
    private void print(long Longnum)
    {
        sw.Write(Longnum);
    }
    private void print(double Doublenum)
    {
        sw.Write(Doublenum);
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
        if (inputInd == inputLine.Length)
            readInput();
        return int.Parse(inputLine[inputInd++]);
    }
    long nextLong()
    {
        if (inputInd == inputLine.Length)
            readInput();
        return long.Parse(inputLine[inputInd++]);
    }
    double nextDouble()
    {
        if (inputInd == inputLine.Length)
            readInput();
        return double.Parse(inputLine[inputInd++]);
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


