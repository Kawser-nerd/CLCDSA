using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = input[0];
        var a = input[1];
        var b = input[2];
        var max = 0L;
        var min = 0L;
        if(n >= 2 && a <= b){
            max = a + b * (n - 1);
            min = a * (n - 1) + b;
            Console.WriteLine(max - min + 1);
        }else if(n == 1 && a == b){
            Console.WriteLine(1);
        }else{
            Console.WriteLine(0);
        }
        
    }
}