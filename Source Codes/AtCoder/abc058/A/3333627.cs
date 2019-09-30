using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int studen = int.Parse(input[0]);
        int checkp = int.Parse(input[1]);
        int c = int.Parse(input[2]);
        if(2*checkp-studen-c == 0){
            WriteLine("YES");
        }else{
            WriteLine("NO");
        }
    }
}