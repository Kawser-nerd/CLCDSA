using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int a = int.Parse(ReadLine());
        int b = int.Parse(ReadLine());
        int h = int.Parse(ReadLine());
        WriteLine(((a+b)*h)/2);
    }
}