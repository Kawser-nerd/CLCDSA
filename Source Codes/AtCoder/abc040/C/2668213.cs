using System;
public class Hello{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(' '),long.Parse);
        var dp = new long[N];
        
        dp[0] = 0;
        dp[1] = Math.Abs(a[1] - a[0]);
        
        for(var i = 2;i < N;i++){
            dp[i] = Math.Min(dp[i - 2] + Math.Abs(a[i - 2] - a[i]),dp[i - 1] + Math.Abs(a[i - 1] - a[i]));
            //2???????????????????????
            //
        }
        
        Console.WriteLine(dp[N - 1]);
    }
}