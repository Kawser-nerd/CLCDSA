using System;
using System.Linq;
using System.Collections.Generic;
public class Test
{
    public static void Main()
    {
        long foo = 0;
        Console.WriteLine("{1}",Console.ReadLine(),new long[]{0}.Concat(Console.ReadLine().Split().Select(s => long.Parse(s))).Select(i=> { foo += i;return foo; }).GroupBy(v=>v).Select(g=>g.LongCount()).Where(i=>i>1).Select(i=>i*(i-1)/2).Sum());
    }
}