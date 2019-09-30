using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
 
public class Program{
    public static void Main(){
        var stream = new StreamWriter(Console.OpenStandardOutput()){AutoFlush=false};
        Console.SetOut(stream);

        var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = input[0], a = input[1], b = input[2];
        var ans = 0;
        for(int i=0; i<n; i++){
            var info = Console.ReadLine().Split().ToArray();
            var dir = info[0];
            var dist = int.Parse(info[1]);
            var x = 1;
            if(dir=="West") x*=-1;
            if(dist<a) ans+=a*x;
            else if(b<dist) ans+=b*x;
            else ans+=dist*x;
        }
        if(ans==0) Console.WriteLine(0);
        else Console.WriteLine(ans<0 ? $"West {ans*-1}" : $"East {ans}");
    
        Console.Out.Flush();
    }
}