using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        string a = input[1][0].ToString();
        WriteLine("A{0}C",a);
    }
}