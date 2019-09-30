using System;
using System.Linq;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var N = line[0];
        var K = line[1];
        var a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var Sums = new long[N + 1];
        long ans = 0;
        Sums[0] = 0;
        for(var i = 0;i < N;i++){
            Sums[i + 1] = Sums[i] + a[i];
        }
        
        for(var i = K;i <= N;i++){
            ans += Sums[i] - Sums[i - K];
        }
        
        Console.WriteLine(ans);
    }
}