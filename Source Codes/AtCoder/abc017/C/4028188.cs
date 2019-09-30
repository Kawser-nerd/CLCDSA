using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        int[] dp = new int[m];
        int sum = 0;
        foreach(int i in Enumerable.Range(0, n))
        {
            inputs = Console.ReadLine().Split();
            int start = int.Parse(inputs[0]) - 1;
            int end   = int.Parse(inputs[1]) - 1;
            int point = int.Parse(inputs[2]);
            sum += point;
            dp[start] += point;
            if(end < m - 1)
            {
                dp[end + 1] -= point;
            }
        }
        foreach(int i in Enumerable.Range(0, m - 1))
        {
            dp[i + 1] += dp[i];
        }
        //Console.WriteLine(string.Join(",", dp));
        int result = sum - dp.Min();
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}