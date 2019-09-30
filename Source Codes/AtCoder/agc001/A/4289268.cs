using System;
using System.Collections.Generic;
using System.Linq;

public class Hello{
    public static void Main(){
        var n = Int32.Parse(Console.ReadLine());
        var li = Console.ReadLine().Split(' ').Select(s => Int32.Parse(s)).OrderBy(i => i).ToList();
        var ret = 0;
        for(var i = 0; i < n * 2; i +=2)  ret += li[i];
        Console.WriteLine(ret);
    }
}