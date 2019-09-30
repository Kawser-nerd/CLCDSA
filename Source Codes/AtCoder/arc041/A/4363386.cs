using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var x = input[0];
        var y = input[1];
        var k = int.Parse(Console.ReadLine());
        
        if(y >= k){
            Console.WriteLine(x + k);
        }else{
            Console.WriteLine(y + x - (k - y));
        }
        
        
    }
}