using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    
    public void slove()
    {
        int n = int.Parse(Console.ReadLine());
        int[] array = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .ToArray();
        int[] dp = new int[n];
        dp[1] = Math.Abs(array[1] - array[0]);
        foreach(int i in array.Select((x, i) => i).Skip(2))
        {
            dp[i] = Math.Min(
                    dp[i - 1] + Math.Abs(array[i] - array[i - 1]),
                    dp[i - 2] + Math.Abs(array[i] - array[i - 2]));
        }
        System.Console.WriteLine(dp[n - 1]);
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}