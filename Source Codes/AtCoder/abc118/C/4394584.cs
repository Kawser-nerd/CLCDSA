using System;
using System.Collections.Generic;
using System.Linq;
 
namespace AtCoderTemplate
{
    public class App
    {
        public static void Main(string[] args)
        {
            Console.ReadLine();
	        var p = Console.ReadLine().Split().Select(s=>long.Parse(s)).OrderBy(i=>i).AsEnumerable();
            Console.WriteLine(p.Aggregate(p.First(),(s,n)=>gcd(s,n)));
        }
        public static long gcd(long a,long b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }
    }
}