using System;
using System.Collections.Generic;
using System.Linq;

class Cmondai
{
    static void Main()
    {
        var N = Int64.Parse(Console.ReadLine());
        const long constant = -2;
        var num = 1L;
        var ans = new Stack<char>();
        if (N == 0) ans.Push('0');
        while (N != 0)
        {
            //???0
            //1?????????????
            if (N % (num * constant) == 0)
            {
                ans.Push('0');
            }
            //???1
            //1????????N??????
            else
            {
                ans.Push('1');
                N -= num;
            }
            num *= (-2);
        }
        long count = ans.Count();
        for(long i=0;i<count;++i)Console.Write(ans.Pop());
        Console.WriteLine();
    }
}