using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
			var s = Console.ReadLine();

			var regex = new Regex(@"^(\d+)-(\d+)$");
			var match = regex.Match(s);
			if (!match.Success)
			{
				Console.WriteLine("No");
				return;
			}

			for (var i = 0; i < 2; i++)
			{
				if (match.Groups[i + 1].ToString().Length != line[i])
				{
					Console.WriteLine("No");
					return;
				}
			}

			Console.WriteLine("Yes");
		}
	}
}