using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{

    
    void solve()
    {
        int n;
        long  k, b, t;
        n = nextInt();
        k = nextInt();
        b = nextInt();
        t = nextInt();
        long[] x = new long[n];
        long[] v = new long[n];
        for (int i = 0; i < n; i++)
        {
            x[i] = nextInt();
           
        }
        for (int i = 0; i < n; i++)
            v[i] = nextInt();
        int num = 0;
        int cnt=0;
        int ret=0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (cnt >= k)
                break;
            if (x[i] + t * v[i] >= b)
            {
                //ok
                cnt++;
                ret += num;
            }
            else
            {
                num++;
            }
        }
        if (cnt < k)
            println("IMPOSSIBLE");
        else
            println(ret);
    
       
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
        inputLine = sr.ReadLine().Split();

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


