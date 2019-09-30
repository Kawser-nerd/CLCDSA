using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        int leng = int.Parse(ReadLine());
        if(leng < 1200){
            WriteLine("ABC");
        }else{
            WriteLine("ARC");
        }
    }
}