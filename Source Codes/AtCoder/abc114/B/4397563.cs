using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

class Program
{
    static void Main(string[] Args) {
        string S = ReadLine();
        if(S.Length <= 2) {
            WriteLine(Math.Abs(753 - Int32.Parse(S)));
            return;
        }

        List<int> Deffs = new List<int>();
        for(int i = 0;i < S.Length - 2; i++) {
            Deffs.Add(Math.Abs(753 - Int32.Parse(S.Substring(i, 3))));
        }

        WriteLine(Deffs.Min());
    }
}