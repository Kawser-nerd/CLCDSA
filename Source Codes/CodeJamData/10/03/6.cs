using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.IO;


class Program
{

    
    void solve()
    {
        int R, K, N;
        R = nextInt();
        K = nextInt();
        N = nextInt();
        bool[] vis = new bool[N];
        long[]amount=new long[N];
        List<int> nums = new List<int>();
        for (int i = 0; i < N; i++)
            nums.Add(nextInt());
        List<int> inds = new List<int>();
        for (int i = 0; i < N; i++)
            inds.Add(i);
        int[] next = new int[N];
        int[] value = new int[N];
        int Len = 0;
        long ret = 0;
        int prev = -1;
        int cnt = 0;
        while (R>0)
        {
            R--;
            List<int> cur = new List<int>();
            int sum = 0;
            int who = inds[0];
            vis[who] = true;
            while (inds.Count>0 && sum+nums[inds[0]]<=K)
            {
                
                cur.Add(inds[0]);
                sum += nums[inds[0]];
                inds.RemoveAt(0);
            }
            inds.AddRange(cur);
            ret += sum;
            value[who] = sum;
            next[who] = inds[0];
            int st = inds[0];
            if (vis[st])
            {
                while (R > 0)
                {
                    R--;
                    ret += value[st];
                    st = next[st];
                }
            }
        }

        sw.WriteLine(ret);
    

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


