using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var A = input[0];
        var B = input[1];
        var K = input[2];
        var L = input[3];
        
        var ans = Math.Min(B * (K / L) + A * (K % L),B * (K / L + 1));
        Console.WriteLine(ans);
        
    }
}