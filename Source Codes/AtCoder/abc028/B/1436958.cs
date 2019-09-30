using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
 
public class Program{
    public static void Main(){
        var stream = new StreamWriter(Console.OpenStandardOutput()){AutoFlush=false};
        Console.SetOut(stream);
        
        var s = Console.ReadLine();
        var dict = new Dictionary<char, int>();
        dict.Add('A', 0);
        dict.Add('B', 0);
        dict.Add('C', 0);
        dict.Add('D', 0);
        dict.Add('E', 0);
        dict.Add('F', 0);
        foreach(var t in s){
            dict[t]++;
        }
        var ans = new string[6];
        int c = 0;
        foreach(var content in dict.OrderBy(o=>o.Key)){
            ans[c] = dict[content.Key].ToString();
            c++;
        }
        
        var r = string.Join(" ", ans);
        Console.WriteLine(r);
        
        Console.Out.Flush();
    }
}