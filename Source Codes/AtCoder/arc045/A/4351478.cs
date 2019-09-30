using System;
using System.Linq;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var sign = new char[]{'<','>','A'};
        var temp = new string[]{"Left","Right","AtCoder"};
        
        var answers = new List<char>();
        
        var s = Console.ReadLine().Split(' ');
        
        foreach(var i in s){
            answers.Add(sign[Array.IndexOf(temp,i)]);
        }
        
        var ans = string.Join(" ",answers);
        Console.WriteLine(ans);
    }
}