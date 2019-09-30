using System;
using System.Collections.Generic;
using System.Linq;
using console=System.Console;
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            var p = console.ReadLine();
            if(p.Count()==26)
            {
                 var q = p.Skip(1).Zip(p,(a,b)=>a-b);
                 var r = p.Count() - 1 - q.Reverse().TakeWhile(i=>i<0).Count();
                 if(r==0)
                 console.WriteLine(-1);
                 else
                 {
                 var s = p.Take(r).ToArray();
                 s[r-1]=p.Last(c=>c>s[r-1]);
                 console.WriteLine(string.Join("",s));
                 }
            }
            else
                console.WriteLine(p +(char)('a'+ p.OrderBy(c=>c).Where((c,i)=>c-i=='a').Count()));
        }
    }
}