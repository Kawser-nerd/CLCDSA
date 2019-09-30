using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        if(input[0] == input[1]){
            WriteLine("H");
        }else{
            WriteLine("D");
        }
    }
}