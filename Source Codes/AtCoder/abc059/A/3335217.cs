using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        WriteLine("{0}{1}{2}",input[0].Substring(0,1).ToUpper(),input[1].Substring(0,1).ToUpper(),input[2].Substring(0,1).ToUpper());
    }
}