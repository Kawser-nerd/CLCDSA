using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var hw = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .ToArray();

        if (hw.Any(x => x % 3 == 0))
        {
            Console.WriteLine(0);
            return;
        }

        var s = hw[0] * hw[1];
        Func<long[], IEnumerable<long>> q = _hw =>
            from hh in Enumerable.Range(1, (int)_hw[1] - 1)
            let sa = _hw[0] * hh
            from rect in new[] 
                { new[] { _hw[0], _hw[1] - hh }
                , new[] { _hw[1] - hh, _hw[0] }
                }
            let sb = rect[0] / 2 * rect[1]
            let ss = new[] { sa, sb, s - sa - sb }
            select ss.Max() - ss.Min();

        Console.WriteLine(Math.Min(q(hw).Min(), q(hw.Reverse().ToArray()).Min()));
    }
}