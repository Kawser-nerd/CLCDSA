using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{


    void solve()
    {
        int n = nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = nextInt();
            b[i] = nextInt();
        }
        Array.Sort(b, a);
        int res = 0;
        int[] state = new int[n];
        int cntTwo = 0;
        int stars = 0;
        while (cntTwo < n)
        {
            bool any = false;
            for (int i = 0; i < n; i++)
                if ((state[i] == 0 || state[i] == 1) && stars >= b[i])
                {
                    stars += 1 - state[i];
                    state[i] = 2;
                    stars++;
                    cntTwo++;
                    res++;
                    any = true;
                }
            if (any)
                continue;
            for (int i = n - 1; i >= 0; i--)
                if (state[i] == 0 && stars >= a[i])
                {
                    res++;
                    stars++;
                    state[i] = 1;
                    any = true;
                    break;
                }
            if (!any)
                break;
        }
        if (cntTwo < n)
            println("Too Bad");
        else
            println(res);

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
