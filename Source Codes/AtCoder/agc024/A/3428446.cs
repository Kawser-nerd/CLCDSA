using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        long a = long.Parse(input[0]);
        long b = long.Parse(input[1]);
        long c = long.Parse(input[2]);
        long d = long.Parse(input[3]);
//        string temp = ReadLine();
//        int a = int.Parse(ReadLine());
//        int b = int.Parse(ReadLine());
//        int c = int.Parse(ReadLine());
//        int d = int.Parse(ReadLine());
//        string a = ReadLine();
//        string b = ReadLine();
//        string c = ReadLine();
//        string ko = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if(d%2==0){
            WriteLine(a-b);
        }else{
            WriteLine(b-a);
        }
    }
}