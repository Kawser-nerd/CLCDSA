using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var array = new long[100001];
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = input[0];
        var k = input[1];
        
        for(var i = 0;i < n;i++){
            var x = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var a = x[0];
            var b = x[1];
            array[a] += b;
        }
        for(var i = 0;i < array.Length;i++){
            if(k <= array[i]){
                Console.WriteLine(i);
                return;
            }else{
                k -= array[i];
            }
        }
    }
}