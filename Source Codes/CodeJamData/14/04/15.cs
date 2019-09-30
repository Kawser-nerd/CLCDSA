using System;
using System.Collections.Generic;
using System.Linq;

class D
{
    Tuple<int, int> Solve(int[] naomi, int[] ken)
    {
        Array.Sort(naomi);
        Array.Sort(ken);

        int kenPos1 = 0;
        int kenPos2 = 0;
        return Tuple.Create(
            naomi.Count(n =>
            {
                if (n < ken[kenPos1]) return false;
                kenPos1++;
                return true;
            }),
            naomi.Length - naomi.TakeWhile(n =>
            {
                if (kenPos2 >= ken.Length) return false;
                kenPos2 = Array.FindIndex(ken, kenPos2, k => n < k) + 1;
                return kenPos2 > 0;
            }).Count()
        );
    }

    static IEnumerable<string> Output()
    {
        Console.ReadLine();
        var masses = new string[] { Console.ReadLine(), Console.ReadLine() }.Select(line => line.Split(' ').Select(m => int.Parse(m.PadRight(7, '0').Substring(2))).ToArray()).ToArray();
        var result = new D().Solve(masses[0], masses[1]);
        yield return result.Item1 + " " + result.Item2;
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}