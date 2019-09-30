using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;

class Program
{

    static void Main(string[] args)
    {
        label:
        WriteLine(d());
        //goto label;
    }

    static int d()
    {
        var sp = ReadLine().Split();
        int sCount = Parse(sp[0]);
        int HP = Parse(sp[1]);
        int furuD = 0;
        var nageD = new List<int>();
        foreach (int i in Enumerable.Range(0, sCount))
        {
            sp = ReadLine().Split();
            furuD = Max(furuD, Parse(sp[0]));
            nageD.Add(Parse(sp[1]));
        }
        nageD = nageD.FindAll(n => furuD < n);
        nageD.Sort();
        for (int i = nageD.Count - 1; 0 <= i; --i)
        {
            HP -= nageD[i];
            if (HP <= 0) return nageD.Count - i;
        }
        return nageD.Count + (HP + furuD - 1) / furuD;
    }
}