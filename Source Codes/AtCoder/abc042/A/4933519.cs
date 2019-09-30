using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        var cnt5 = input.Where(d => d == 5).Count();
        var cnt7 = input.Where(d => d == 7).Count();
        
        if (cnt5 == 2 && cnt7 == 1) {
            Console.WriteLine("YES");
        } else {
            Console.WriteLine("NO");   
        }
	}
}