using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;

public class Solver
{
    private int cs, rs;
    private bool[,] obstacle;
    private bool[,] used;
    int[] dr = new int[] {0, 1, 0, -1};
    int[] dc = new int[] {-1, 0, 1, 0};
    
    bool Dfs(int r, int c, bool[,] visited, int dir)
    {
        if (r == rs)
            return true;
        if (r < 0 || c < 0 || c == cs || obstacle[r, c] || used[r, c] || visited[r, c])
            return false;
        visited[r, c] = true;

        int nd = dir - 1;
        if (nd < 0)
            nd = 3;
        if (Dfs(r + dr[nd], c + dc[nd], visited, nd))
        {
            used[r, c] = true;
            return true;
        }
        if (Dfs(r + dr[dir], c + dc[dir], visited, dir))
        {
            used[r, c] = true;
            return true;
        }
        nd = dir + 1;
        if (nd > 3)
            nd = 0;
        if (Dfs(r + dr[nd], c + dc[nd], visited, nd))
        {
            used[r, c] = true;
            return true;
        }
        return false;
    }

    public void Solve()
    {
        cs = ReadInt();
        rs = ReadInt();
        int b = ReadInt();

        obstacle = new bool[rs, cs];
        for (int k = 0; k < b; k++)
        {
            int x0 = ReadInt();
            int y0 = ReadInt();
            int x1 = ReadInt();
            int y1 = ReadInt();
            for (int i = y0; i <= y1; i++)
                for (int j = x0; j <= x1; j++)
                    obstacle[i, j] = true;
        }

//        for (int i = 0; i < rs; i++)
//        {
//            for (int j = 0; j < cs; j++)
//                writer.Write(obstacle[i, j] ? '*' : '.');
//            writer.WriteLine();
//        }

        used = new bool[rs, cs];

        int ans = 0;
        for (int j = 0; j < cs; j++)
        {
            if (Dfs(0, j, new bool[rs,cs], 0))
                ans++;
        }
        writer.WriteLine(ans);

    }

    #region Main
    protected static TextReader reader;
    protected static TextWriter writer;

    static void Main()
    {
        reader = new StreamReader("..\\..\\input.txt");
        writer = new StreamWriter("..\\..\\output.txt");
        //writer = Console.Out;
        Solver solver = new Solver();


        int t = ReadInt();
        for (int i = 0; i < t; i++)
        {
            writer.Write("Case #{0}: ", i + 1);
            Thread thread = new Thread(solver.Solve, 20 * 1024 * 1024);
            thread.Start();
            thread.Join();

            //solver.Solve();
        }

        reader.Close();
        writer.Close();
    }

    #endregion

    #region Read/Write

    static Queue<string> currentLineTokens = new Queue<string>();

    public static string ReadToken()
    {
        if (currentLineTokens.Count == 0)
        {
            currentLineTokens = new Queue<string>(reader.ReadLine().Trim().Split(' '));
        }
        return currentLineTokens.Dequeue();
    }

    public static string[] ReadTokens(bool fromCurrentLine = false)
    {
        string[] split;
        if (fromCurrentLine)
        {
            if (currentLineTokens.Count == 0)
                return new string[0];
            split = currentLineTokens.ToArray();
            currentLineTokens.Clear();
        }
        else
        {
            split = reader.ReadLine().Trim().Split(' ');
        }
        return split;
    }

    public static int ReadInt()
    {
        return int.Parse(ReadToken());
    }

    public static long ReadLong()
    {
        return long.Parse(ReadToken());
    }

    public static double ReadDouble()
    {
        return double.Parse(ReadToken());
    }

    public static int[] ReadIntArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(int.Parse).ToArray();
    }

    public static long[] ReadLongArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(long.Parse).ToArray();
    }

    public static double[] ReadDoubleArray(bool fromCurrentLine = false)
    {
        string[] tokens = ReadTokens(fromCurrentLine);
        return tokens.Select(double.Parse).ToArray();
    }

    public static int[][] ReadIntMatrix(int numberOfRows)
    {
        int[][] matrix = new int[numberOfRows][];
        for (int i = 0; i < numberOfRows; i++)
            matrix[i] = ReadIntArray();
        return matrix;
    }

    public static string[] ReadLines(int quantity)
    {
        string[] lines = new string[quantity];
        for (int i = 0; i < quantity; i++)
        {
            lines[i] = reader.ReadLine().Trim();
        }
        return lines;
    }

    public static void WriteArray<T>(IEnumerable<T> array)
    {
        writer.WriteLine(string.Join(" ", array));
    }

    #endregion
}