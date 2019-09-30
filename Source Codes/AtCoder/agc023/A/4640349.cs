using System;
using System.Linq;
public class Test
{
    public static void Main(string[] vs)=>Console.WriteLine("{2}",vs=new string[1] {"0"}, Console.ReadLine(), new long[] { 0 }.Concat(Console.ReadLine().Split().Select(s => long.Parse(s))).Select(i => vs[0] = (long.Parse(vs[0]) + i).ToString()).GroupBy(v => v).Select(g => g.LongCount()).Where(i => i > 1).Select(i => i * (i - 1) / 2).Sum());
}