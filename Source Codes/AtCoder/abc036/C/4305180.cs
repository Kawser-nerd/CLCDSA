using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;

class Program
{
    struct P
    {
        public int index;
        public int height;
        public P(int index,int height)
        {
            this.index = index;
            this.height = height;
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = new P[num];
        for (var i = 0; i < num; i++)
            ar[i] = new P(i,ToInt32(ReadLine()));
        ar = ar.OrderBy(p => p.height).ToArray();
        var index = -1;
        var then = 0;
        for(var i = 0; i < num; i++)
        {
            if (ar[i].height == then) ar[i].height = index;
            else
            {
                index++;
                then = ar[i].height;
                ar[i].height = index;
            }
        }
        ar = ar.OrderBy(p => p.index).ToArray();
        for (var i = 0; i < num; i++)
            WriteLine(ar[i].height);
    }
}