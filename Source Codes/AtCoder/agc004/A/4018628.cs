using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var min = long.MaxValue;
        
        for(var i = 0;i < 3;i++){
            var a = 1L;
            var b = 1L;
            
            for(var j = 0;j < 3;j++){
                if(i == j){
                    a *= input[j] / 2;
                    b *= input[j] - input[j] / 2;
                }else{
                    a *= input[j];
                    b *= input[j];
                }
            }
            min = Math.Min(min,Math.Abs(a - b));
        }
        Console.WriteLine(min);
    }
}