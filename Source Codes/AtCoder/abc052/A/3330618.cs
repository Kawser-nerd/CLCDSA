using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int aa = int.Parse(input[0]);
        int ab = int.Parse(input[1]);
        int ba = int.Parse(input[2]);
        int bb = int.Parse(input[3]);
        WriteLine(Max(aa*ab,ba*bb));
    }
}