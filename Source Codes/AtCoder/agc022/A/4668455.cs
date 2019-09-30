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
            args=new string[2];
            args[0] = console.ReadLine();
            if(args[0].Count()==26)
            {
                 var q = 25 - args[0].Skip(1).Zip(args[0],(a,b)=>a-b).Reverse().TakeWhile(i=>i<0).Count();
                 if(q==0)
                 console.WriteLine(-1);
                 else
                 {
                 var s = args[0].Take(q).ToArray();
                 s[q-1]=args[0].Last(c=>c>s[q-1]);
                 console.WriteLine(s);
                 }
            }
            else
                console.WriteLine(args[0] +(char)('a'+ args[0].OrderBy(c=>c).Where((c,i)=>c-i=='a').Count()));
        }
    }
}