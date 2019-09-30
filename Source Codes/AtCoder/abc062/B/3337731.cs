using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = 2+int.Parse(input[1]);
        for(int i=0;i<b;i++){
            Write("#");
        }
        WriteLine("");
        
        for(int i=0;i<a;i++){
            string temp = ReadLine();
            WriteLine("#"+temp+"#");
        }
        
        for(int i=0;i<b;i++){
            Write("#");
        }
        WriteLine("");
    }
}