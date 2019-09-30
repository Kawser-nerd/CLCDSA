using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
 
public class Hello{
    public static void Main(){
        string[] input = ReadLine().Split(' ');
        int n = int.Parse(input[0]);
        int m = int.Parse(input[1]);
//        string temp = ReadLine();
        int a = 0;
        for(int i=1;i<999;i++){
            int x1 = (i*(i+1))/2-n;
            int x2 = ((i+1)*(i+2))/2-m;
            if(x1 == x2){
                WriteLine(x1);
            }
        }
    }
}