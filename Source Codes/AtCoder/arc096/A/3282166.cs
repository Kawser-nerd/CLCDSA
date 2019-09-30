using System;
using static System.Console;
using static System.Math;

public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int ab = int.Parse(input[2]);
        int x = int.Parse(input[3]);
        int y = int.Parse(input[4]);
        
        int xa = x*a;
        int yb = y*b;
        int total=xa+yb;
        int maxxy = Max(x,y);
        int minxy = Min(x,y);
        if(total > ab*maxxy*2){
            total = ab*maxxy*2;
        }
        if(minxy == x){
            if(total > (ab*minxy*2) + (b*(y-x)) ){
                total = (ab*minxy*2) + (b*(y-x));
            }
        }else if(minxy == y){
            if(total > (ab*minxy*2) + (a*(x-y)) ){
                total = (ab*minxy*2) + (a*(x-y));
            }
        }
        WriteLine(total);
    }
}