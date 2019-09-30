using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int leng = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        if(leng == 1){
            leng+=13;
        }
        if(b == 1){
            b+=13;
        }
        if(leng > b){
            WriteLine("Alice");
        }else if(b > leng){
            WriteLine("Bob");
        }else if(leng == b){
            WriteLine("Draw");
        }
    }
}