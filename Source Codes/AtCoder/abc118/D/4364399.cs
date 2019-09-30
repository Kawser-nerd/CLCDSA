using System;
using System.Linq;
using System.Collections.Generic;
public class Hello
{
    public static void Main()
    {
        
        int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int N = a[0];
        int M = a[1];
        int[] A = Console.ReadLine().Split(' ').Select(y => int.Parse(y)).ToArray();
        
        //?????????????????
        int[] dp = new int[N + 10]; //dp[i] : ????i?????????????????????????????
        dp[0] = 0;
        
        for(int i = 1; i <= N; i++)
        {
            int max = -10;
            for(int j = 0; j < M; j++)
            {
                try
                {
                    max = Math.Max(max, dp[i - num(A[j])] + 1);
                }
                catch(IndexOutOfRangeException)
                {
                    continue;
                }
            }
            dp[i] = max;
        }
            
    ??//??????????????????????
        int remain = dp[N]; //?????
        int match = N; //?????????
        string ans = "";
        Array.Sort(A);
        
        
        while(match > 0)
        {
            for(int i = M - 1; i >= 0; i--)
            {
                try
                {
                    if(dp[match - num(A[i])] == remain - 1)
                    {
                        
                        ans += A[i];
                        match -= num(A[i]);
                        remain--;
                        break;
                    }
                }
                catch(IndexOutOfRangeException)
                {
                    continue;
                }
                
            }
        }
        
        Console.WriteLine(ans);
    }
    
    public static int num(int x)
    {
        int[] c = {0,2,5,5,4,5,6,3,7,6};
        return c[x];
    }
}