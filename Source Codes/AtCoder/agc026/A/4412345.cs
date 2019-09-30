using System;
    using System.Collections.Generic;
    using static System.Console;
    using System.Linq;


class Program
{

    static void Main(string[] Args) {
        ReadLine();
        var a = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();
        var renzoku = new List<int>();

        for (int Count = 0; Count < a.Count(); Count++) {
            int tmp = 0;
            int first = a[Count];
            for(tmp = 1; ; tmp++) {
                try {
                    if (a[Count + tmp] != first) break;
                } catch(Exception) { break; }
            }
            Count += tmp - 1;
            renzoku.Add(tmp);
        }

        int Result = 0;

        foreach(int ele in renzoku) {
            if (ele % 2 == 0) Result += ele / 2;
            else Result += (ele - 1) / 2;
        }

        WriteLine(Result);

        ReadLine();
    }
}