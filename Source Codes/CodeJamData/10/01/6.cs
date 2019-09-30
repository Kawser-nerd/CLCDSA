using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{


    void solve()
    {

        int N = nextInt();
        long K = nextInt();
        if (K % (1L << N) == (1L << N) - 1)
            sw.WriteLine("ON");
        else
            sw.WriteLine("OFF");

    }

    //




    void read()
    {

        int testCases = int.Parse(nextLine());
        for (int test = 1; test <= testCases; test++)
        {
            sw.Write("Case #" + test + ": ");
            solve();

        }
        close();
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


