using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    const string inputName = @"C-small-attempt1.in";
    //const string inputName = @"test.txt";
    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\" + inputName);
    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C.txt");

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    int N;
    int M;
    const int dir = 4;
    int[] dx = new int[dir] { 1, 0, -1, 0 };
    int[] dy = new int[dir] { 0, 1, 0, -1 };
    //const string direction = "DRUL";
    //const string direction = "SENW";

    private string Solve()
    {
        var split = intSplit(' ');
        N = split[0];
        M = split[1];
        int K = split[2];
        int res = K;
        int mul = N * M;
        int max = 1 << mul;
        var color = new bool[N,M];
        var used = new bool[N, M];
        for (int mask = 0; mask < max; mask++)
        {
            if (BitCount(mask)>=res)
            {
                continue;
            }//if
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    color[i, j] =used[i,j] =  false;
                }//for j
            }//for i
            for (int k = 0; k < mul; k++)
            {
                if ((mask>>k&1)==1)
                {
                    color[k / M, k % M] = true;
                }//if
            }//for k
            var que = new Queue<int>();
            for (int i = 0; i < N; i++)
            {
                Add(M, color, used, que, i, 0);
                Add(M, color, used, que, i, M-1);
            }//for i
            for (int j = 0; j < M; j++)
            {
                Add(M, color, used, que, 0, j);
                Add(M, color, used, que, N - 1, j);
            }//for j
            while (que.Count>0)
            {
                int deq = que.Dequeue();
                int x = deq / M;
                int y = deq % M;
                for (int arround = 0; arround < dir; arround++)
                {
                    int nx = x + dx[arround];
                    int ny = y + dy[arround];
                    if (!Inside(nx, ny)||color[nx,ny]||used[nx,ny])
                        continue;
                    Add(M, color, used, que, nx, ny);
                }//for arround
            }//while
            int cnt = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (!used[i,j])
                    {
                        cnt++;
                    }//if
                }//for j
            }//for i
            if (cnt>=K)
            {
                res = Math.Min(res, BitCount(mask));
            }//if
        }//for i
        return res.ToString();
    }

    private static void Add(int M, bool[,] color, bool[,] used, Queue<int> que, int i, int p)
    {
        if (!color[i, p])
        {
            used[i, p] = true;
            que.Enqueue(i * M + p);
        }//if
    }

    /// <summary>
    /// varified by SRM DIV1 Medium 407 PointsGame
    /// varified by SRM DIV1 430 Hard PickingUp
    /// BitCount を数える
    /// O( log n )
    /// </summary>
    /// <param name="n">入力の値</param>
    /// <returns>2進表現における1の数</returns>
    public static int BitCount(long n)
    {
        int res = 0;
        for (; n > 0; n &= n - 1)
            res++;
        return res;
    }//BitCount

    
    public bool Inside(int x, int y)
    {
        return 0 <= x && x < N && 0 <= y && y < M;
    }//Inside

    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName