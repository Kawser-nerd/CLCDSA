using static System.Console;
using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var s = ReadLine();
        var n = int.Parse(ReadLine());
        if(s.Length < n) {
            WriteLine(0);
            return;
        }
        var li = new List<string>();
        int i = 0;
        while(i + n <= s.Length) {
            li.Add(s.Substring(i, n));
            i++;
        }
        WriteLine(li.Distinct().Count());
    }
}