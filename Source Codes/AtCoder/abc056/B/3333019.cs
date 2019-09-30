using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int w = int.Parse(input[0]);
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);
        if(Abs(a-b) <= w){
            WriteLine("0");
        }else{
            WriteLine(Abs(a-b)-w);
        }
    }
}