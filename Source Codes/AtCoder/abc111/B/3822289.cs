using System;
using System.Collections.Generic;
using System.Linq;
class Program{
    static void Main(){
        int n = int.Parse(Console.ReadLine());
        int[] X = {111,222,333,444,555,666,777,888,999};
        var q = from x in X
            where x >= n
            select x;
        Console.WriteLine(q.Min());
    }
}