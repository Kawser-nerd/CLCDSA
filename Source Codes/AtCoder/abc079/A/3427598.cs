using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
//        string[] input = ReadLine().Split(' ');
/*        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);
        int b = int.Parse(input[2]);*/
//        string temp = ReadLine();
        int a = int.Parse(ReadLine());
//        int b = int.Parse(ReadLine());
//        string a = ReadLine();
//        string b = ReadLine();
        int b = a/10;
        a = a%1000;
        if(a%111==0 || b%111==0){
            WriteLine("Yes");
        }else{
            WriteLine("No");
        }
    }
}