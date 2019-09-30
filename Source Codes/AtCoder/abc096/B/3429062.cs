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
//        long d = long.Parse(input[3]);*/
//        string temp = ReadLine();
//        int a = int.Parse(ReadLine());
//        int b = int.Parse(ReadLine());
//        int c = int.Parse(ReadLine());
//        int d = int.Parse(ReadLine());
//        string a = ReadLine();
//        string b = ReadLine();
//        string c = ReadLine();
//        string[] input = ReadLine().Split(' ');
//        string ko = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        long max = Max(a,Max(b,c));
        int temp = int.Parse(ReadLine());
        for(int i=0;i<temp;i++){
            max*=2;
        }
        if(a>=b && a>=c){
            WriteLine(max+b+c);
        }else if(b>=a && b>=c){
            WriteLine(max+a+c);
        }else{
            WriteLine(max+a+b);
        }
    }
}