using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var arr = new long[1000002];
        var n = long.Parse(Console.ReadLine());
        
        for(var i = 0;i < n;i++){
            var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var a = input[0];
            var b = input[1];
            arr[a]++;
            arr[b + 1]--;
        }
        var max = arr[0];
        for(var i = 1;i <= 1000000;i++){
            arr[i] += arr[i - 1];
            max = Math.Max(arr[i],max);
        }
        Console.WriteLine(max);
    }
}