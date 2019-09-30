using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var S = Console.ReadLine();
        var T = Console.ReadLine();
        var sUniq = S.Distinct().ToArray();
        var tUniq = T.Distinct().ToArray();
        var ans = "Yes";
        if (sUniq.Count() != tUniq.Count()) ans = "No";
        for (int i=0; i<sUniq.Count();++i)
        {
            if (ans == "No") break;
            if (S.Count(x => x == sUniq[i])!=T.Count(x => x == tUniq[i])) ans = "No";
        }
        Console.WriteLine(ans);
    }
}