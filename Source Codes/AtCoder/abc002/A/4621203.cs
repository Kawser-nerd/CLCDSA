using System;
using System.Collections.Generic;
using System.Linq;
 
namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var inputWords = Console.ReadLine().Split(' ');
			var m = int.Parse(inputWords[0]);
			var n = int.Parse(inputWords[1]);
          
			Console.WriteLine(m > n ? m : n);
		}
	}
}