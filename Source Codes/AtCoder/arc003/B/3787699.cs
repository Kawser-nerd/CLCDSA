using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
using System.Globalization;

class Program
{
    struct P
    {
        public string str;
        public string rev;
        public P(string str)
        {
            this.str = str;
            this.rev = string.Join("",str.Reverse());
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var strs = new P[num];
        for (var i = 0; i < num; i++)
            strs[i] = new P(ReadLine());
        strs=strs.OrderBy(p => p.rev).ToArray();
        for (var i = 0; i < num; i++)
            WriteLine(strs[i].str);

    }
}