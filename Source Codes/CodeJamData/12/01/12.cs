using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    public string Solve(string input)
    {
        var sample = new Dictionary<string,string> { 
            {"zq", "qz"},
            {"ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand"},
            {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities"},
            {"de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up"}
        };
        var convert = sample.SelectMany(samp => samp.Key.Select((c, i) => Tuple.Create(c, samp.Value[i])))
                .Distinct().ToDictionary(x => x.Item1, x => x.Item2);
        return new string(input.Select(c=>convert[c]).ToArray());
    }

    static IEnumerable<string> Output() { yield return new A().Solve(Console.ReadLine()); }
    static void Main()
    {
        foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine())))
            Console.Write(Output().Aggregate(string.Format("Case #{0}: ", i), (a, b) => a + b + Environment.NewLine));
    }
}

