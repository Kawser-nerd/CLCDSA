using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            int h,w;
            {
                var tmp = Console.ReadLine().Split(' ')
                .Select(i=>int.Parse(i)).ToArray();
                h = tmp[0];
                w = tmp[1];
            }
            {
                string[] str = new string[h];
                for(int i = 0;i<h;i++)
                {
                    str[i] = Console.ReadLine();
                }
                var p = str.Select((s,i)=>s.ToCharArray().Select((c,j)=>new{c,i,j})).SelectMany(v=>v).GroupBy(v=>v.j).Where(v=>v.Any(x=>x.c=='#')).SelectMany(v=>v).GroupBy(v=>v.i).Where(v=>v.Any(x=>x.c=='#')).Select(v=>v.OrderBy(x=>x.j).ToArray()).OrderBy(v=>v[0].i).ToArray();
                for(int i = 0;i<p.Length;i++)
                {
                    for(int j = 0;j<p.First().Length;j++)
                    {
                       Console.Write(p[i][j].c);
                    }
                   Console.WriteLine();
                }
            }
        }
    }
}