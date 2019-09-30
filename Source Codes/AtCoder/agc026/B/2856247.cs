using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

public class Program{
    public static void Main(){
        var N = int.Parse(ReadLine());
        for(int i=0;i<N;i++){
            var line = ReadLine().Split(' ').Select(x=>ulong.Parse(x)).ToArray();
            WriteLine(Judge(line));
        }
    }
    static string Judge(ulong[] array){
        var A = array[0];
        var B = array[1];
        var C = array[2];
        var D = array[3];
        if(B>A||B>D) return "No";
        if(B <= C) return "Yes";
        var g = GetGcd(B,D);
        if(B-g+(A%g) > C) return "No";
        else return "Yes";
    }
    public static ulong GetGcd(ulong a, ulong b)
    {
        return b != 0 ? GetGcd(b, a % b) : a;
    }

}
//var N = long.Parse(ReadLine());