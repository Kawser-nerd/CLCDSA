using System;
using System.Collections.Generic;
using System.Linq;

public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var N = input[0];
        var K = input[1];
        var nums = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var sum = new long[N + 1];
        long ans = 0;
        sum[0] = 0;
        for(var i = 1;i < N + 1;i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for(var i = K;i < N + 1;i++){
            ans += sum[i] - sum[i - K];
        }
        Console.WriteLine(ans);
    }
}