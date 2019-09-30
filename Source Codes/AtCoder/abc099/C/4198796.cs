using System;
using System.Linq;

public class Hello
{
    public static void Main()
    {
        
        
        int[] dp = new int[100010];
        dp[0] = 0;
        for(int n = 1; n <= 100000; n++)
        {
            dp[n] = 100000;
            
            int power = 1;
            while(power <= n)
            {
                dp[n] = Math.Min(dp[n], 1 + dp[n - power]);
                power *= 6; 
            }
            
            power = 1;
            while(power <= n)
            {
                dp[n] = Math.Min(dp[n], 1 + dp[n - power]);
                power *= 9; 
            }
            
        }
        
        int N = int.Parse(Console.ReadLine());
        Console.WriteLine(dp[N]);
        
        
    }
}