using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static int GetMaxOfRect(int[][] cSum, int width, int height)
    {
        int[][] data = Enumerable.Range(0, cSum[0].Length - height + 1)
            .Select(x => new int[cSum.Length - width + 1])
            .ToArray();
        
        foreach(int row in Enumerable.Range(0, data.Length))
            foreach(int column in Enumerable.Range(0, data[0].Length))
            {
                data[row][column] = cSum[row + height - 1][column + width - 1];
                if(row != 0)
                {
                    data[row][column] -= cSum[row - 1][column + width - 1];
                }
                if(column != 0)
                {
                    data[row][column] -= cSum[row + height - 1][column - 1];
                }
                if(row != 0 && column != 0)
                {
                    data[row][column] += cSum[row - 1][column - 1];
                }
            }
        //Console.WriteLine($"{width} {height}");
        return data.Select(x => x.Max()).Max();
    }
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int[][] plate =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        int[][] cSum = 
            Enumerable.Range(0, n)
            .Select(x => new int[n]).ToArray();
        foreach(int row in Enumerable.Range(0, n))
            foreach(int column in Enumerable.Range(0, n))
            {
                cSum[row][column] = plate[row][column];
                if(row != 0)
                {
                    cSum[row][column] += cSum[row - 1][column];
                }
                if(column != 0)
                {
                    cSum[row][column] += cSum[row][column - 1];
                }
                if(row != 0 && column != 0)
                {
                    cSum[row][column] -= cSum[row - 1][column - 1];
                }
            }
        int q = int.Parse(Console.ReadLine());
        int[] ps =
            Enumerable.Range(0, q)
            .Select(x => Console.ReadLine())
            .Select(int.Parse)
            .ToArray();
        int[] dp = new int[ps.Max() + 1];
        foreach(int i in Enumerable.Range(1, dp.Length - 1))
        {
            foreach(int j in Enumerable.Range(1, n).Skip((i - 1) / n).Where(x => i % x == 0))
            {
                dp[i] = Math.Max(dp[i], GetMaxOfRect(cSum, j, i / j));
            }
        }
        foreach(int i in Enumerable.Range(1, dp.Length - 1))
            dp[i] = Math.Max(dp[i], dp[i - 1]);
        var result = 
            ps.Select(x => dp[x]);
        Console.WriteLine(string.Join("\n", result));
        //Console.WriteLine(string.Join("\n", dp));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}