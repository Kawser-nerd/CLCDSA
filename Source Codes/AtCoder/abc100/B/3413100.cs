using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        long n = long.Parse(input[0]);
        long m = long.Parse(input[1]);
        if(m==100){
            m++;
        }
 
//        int kazu = int.Parse(ReadLine());
//        string[,] map = new string[kazu,kazu];
        for(int i=0;i<n;i++){
            m*=100;
        }
        WriteLine(m);
    }
}