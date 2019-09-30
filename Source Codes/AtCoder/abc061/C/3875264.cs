using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var a = new long[100001];
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = input[0];
        var k = input[1];
        
        for(var i = 0;i < n;i++){
            var x = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var value = x[0];
            var index = x[1];
            a[value] += index;
        }
        for(var i = 0;i < a.Length;i++){
            if(k <= a[i]){
                Console.WriteLine(i);
                return;
            }else{
                k -= a[i];
            }
        }
    }
}