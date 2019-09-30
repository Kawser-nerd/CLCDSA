using System;
using System.Linq;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var a = input[0];
        var b = input[1];
        var ans = "";
        if(1 <= b){
            if(1 <= a){
                ans = "Positive";
            }else{
                ans = "Zero";
            }
        }else if(b == 0){
            ans = "Zero";
        }else{
            if((Math.Abs(a - b) + 1)% 2 == 0){
                ans = "Positive";
            }else{
                ans = "Negative";
            }
        }
        Console.WriteLine(ans);
    }
}