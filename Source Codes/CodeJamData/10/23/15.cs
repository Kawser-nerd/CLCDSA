using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{

    int mod = 100003;
    int[,] binom;
    int[,] dp;
    int maxn = 505;
    void solve()
    {
        if (binom == null)
        {
            binom = new int[maxn + 1, maxn + 1];
            for (int i = 0; i <= maxn; i++)
            {
                binom[i, 0] = 1;
                for (int j = 1; j <= i; j++)
                    binom[i, j] = (binom[i - 1, j - 1] + binom[i - 1, j]) % mod;
            }
            dp = new int[maxn + 1, maxn + 1];
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn; j++)
                    dp[i, j] = -1;
        }
        int n = nextInt();
        int ret = 0;
        for (int ind = 1; ind <= n - 1; ind++)
        {
            ret += go(ind, n);
            ret %= mod;
        }
        
        println(ret);
        Console.WriteLine(ret);
        
    
       
    }

    private int go(int ind, int n)
    {
        if (ind == 1)
        {
            return 1;
        }
        if (dp[ind, n] != -1)
            return dp[ind, n];
        int ret = 0;
        for (int indOfInd = 1; indOfInd <= ind - 1; indOfInd++)
        {
            ret+=(int)((long)go(indOfInd,ind)*binom[n-ind-1,ind-indOfInd-1])%mod;
            ret %= mod;
        }
        return dp[ind,n]=ret;
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


