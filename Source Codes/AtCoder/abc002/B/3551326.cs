using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			var input = Console.ReadLine();
			var result = Regex.Replace(input, "[a,i,u,e,o]", "");
			Console.WriteLine(result);
		}
	}
}