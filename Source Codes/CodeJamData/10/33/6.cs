using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Globalization;

public class A
{
    public static void Main(string[] args)
    {
        int testCases = int.Parse(Console.ReadLine());

        List<string> output = new List<string>(testCases * 10);
        for (int i = 0; i < testCases; i++)
        {
            var mn = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var m = mn[0];
            var n = mn[1];
            var board = MakeBoard(ReadStrings(m));
            var list = CountThem(board);
            output.Add(string.Format("Case #{0}: {1}", i + 1, list.Count));
            var arr = list.Select(l => new { Size = l.Key, Count = l.Value }).OrderByDescending(l => l.Size).ToArray();
            for (int j = 0; j < arr.Length; j++)
            {
                output.Add(string.Format("{0} {1}", arr[j].Size, arr[j].Count));
            }
        }
        foreach (string line in output)
        {
            Console.WriteLine(line);
        }
    }

    private static Dictionary<int, int> CountThem(bool?[][] board)
    {
        Dictionary<int, int> sizes = new Dictionary<int, int>();
        int maxBoardSize = board.Length > board[0].Length ? board[0].Length : board.Length;
        for (int size = maxBoardSize; size >= 1; size--)
        {
            for (int i = 0; i <= board.Length - size; i++)
            {
                for (int j = 0; j <= board[i].Length - size; j++)
                {
                    if (Ok(board, i, j, size))
                    {
                        if (!sizes.ContainsKey(size))
                            sizes.Add(size, 0);
                        sizes[size]++;
                        j += size - 1;
                    }
                }
            }
        }
        return sizes;
    }

    private static bool Ok(bool?[][] board, int top, int left, int size)
    {
        if (board[top][left] == null)
            return false;
        bool start = board[top][left].Value;
        for (int i = top; i < top + size; i++)
        {
            for (int j = left; j < left + size; j++)
            {
                var temp = board[i][j];
                if (temp == null)
                    return false;
                if (i > 0 && i>top)
                    if(temp == board[i - 1][j])
                        return false;
                if (j > 0 && j > left)
                    if (temp == board[i][j-1])
                        return false;
            }
        }

        for (int i = top; i < top + size; i++)
            for (int j = left; j < left + size; j++)
                board[i][j] = null;

        return true;
    }

    private static bool?[][] MakeBoard(string[] p)
    {
        bool?[][] res = new bool?[p.Length][];
        for (int i = 0; i < p.Length; i++)
        {
            res[i] = new bool?[p[0].Length * 4];
            var str = p[i];
            for (int j = 0; j < str.Length; j++)
            {
                int d = int.Parse(str[j].ToString(), NumberStyles.HexNumber);
                int jj = j * 4;
                res[i][jj] = (d & 8) > 0;
                res[i][jj + 1] = (d & 4) > 0;
                res[i][jj + 2] = (d & 2) > 0;
                res[i][jj + 3] = (d & 1) > 0;
            }
        }
        return res;
    }


    #region Read
    private static string[] ReadStrings(int length)
    {
        string[] result = new string[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = Console.ReadLine();
        }
        return result;
    }
    private static int[] ReadInts(int length)
    {
        int[] result = new int[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = int.Parse(Console.ReadLine());
        }
        return result;
    }
    private static long[] ReadLong(int length)
    {
        long[] result = new long[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = long.Parse(Console.ReadLine());
        }
        return result;
    }
    private static float[] ReadFloat(int length)
    {
        float[] result = new float[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = float.Parse(Console.ReadLine());
        }
        return result;
    }
    private static double[] ReadDouble(int length)
    {
        double[] result = new double[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = double.Parse(Console.ReadLine());
        }
        return result;
    }
    #endregion
}