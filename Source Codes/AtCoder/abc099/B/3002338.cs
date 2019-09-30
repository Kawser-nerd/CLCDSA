using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program{
    public static void Main(){
        string[] S = ReadLine().Split(' ');
        int a = int.Parse(S[0]);
        int b = int.Parse(S[1]);
        int ans = (b - a - 1)*(b - a) / 2 - a;
        WriteLine(ans);
    } 
}