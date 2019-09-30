using System;
using System.Linq;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var n = long.Parse(Console.ReadLine());
        var min = long.MaxValue;
        var list = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
        for(var i = list.Min();i <= list.Max();i++){
            var temp = 0L;
            for(var j = 0;j < n;j++){
                temp += (long)Math.Pow(list[j] - i,2);
            }
            min = Math.Min(temp,min);
        }
        Console.WriteLine(min);
    }
}