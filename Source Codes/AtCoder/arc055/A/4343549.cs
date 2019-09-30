using System;
using System.Linq;
public class Hello{
    public static void Main(){
        var N = int.Parse(Console.ReadLine());
        var s = "1";
        for(var i = 0;i < N - 1;i++){
            s += "0";
        }
        s += "7";
        Console.WriteLine(s);
        
    }
}