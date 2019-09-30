using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{


    void solve()
    {
        int type = nextInt();
        int tot = nextInt();
        double[] p = new double[type];
        for (int i = 0; i < p.Length; i++)
            p[i] = nextDouble();
        double res = 1 + tot + 1;
        double curP = 1.0;
        for (int i = 0; i <= type; i++)
        {

            double cur = curP * (tot - i + type - i + 1) + (1 - curP) * (tot - i + type - i + 1+tot+1);
            res = Math.Min(res, cur);
            if (i != type)
                curP *= p[i];
        }
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
