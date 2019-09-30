using System;
using System.Collections.Generic;
using System.Linq;
using console = System.Console;

namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            var p = (IEnumerable<int>)(console.ReadLine().Split().Skip(1).Concat(console.ReadLine().Split()).Select(s=>int.Parse(s)).OrderBy(i=>i));
            p = p.Skip(1).Zip(p,(a,b)=>a-b);
            console.WriteLine(p.Aggregate(p.First(),(s,n)=>gcd(s,n)));
        }
        public static int gcd(int a,int b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }
    }
}