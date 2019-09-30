using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
 
public class Program{
    public static void Main(){
        var stream = new StreamWriter(Console.OpenStandardOutput()){AutoFlush=false};
        Console.SetOut(stream);
        
        var input = Console.ReadLine().Split().Select(double.Parse).ToArray();        
        double n = (input[0])%12*30, m = input[1]*6;
        /*
        ???360???????30?????????
        ????1????1/12???????
        */
        n+=m/12;
        var ans = Math.Min(Math.Abs(n-m)%360, Math.Abs(m-n)%360);
        if(ans>180)ans=360-ans;
        Console.WriteLine(ans);

        Console.Out.Flush();
    }
}