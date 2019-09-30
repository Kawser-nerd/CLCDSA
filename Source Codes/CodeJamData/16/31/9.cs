using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam16._1C._1 {
	class Program {
		static void Main(string[] args) {
			using (var input = new StreamReader("in"))
			using (var output = new StreamWriter("out")) {
				var cases = int.Parse(input.ReadLine());
				for (var i = 0; i < cases; i++)
				{
					var count = int.Parse(input.ReadLine());
					var result = solve(input.ReadLine().Split(' ').Select(int.Parse).Take(count).ToList());
					output.WriteLine($"Case #{i + 1}: {result?.ToString() ?? "INSOMNIA"}");
				}
			}
		}

		static string solve(List<int> s)
		{
			var result = new List<string>();
			while (s.Any(p => p > 0))
			{
				result.Add(evac(ref s));
			}
			return string.Join(" ", result);
		}

		static string evac(ref List<int> s)
		{
			var maxInd = s.IndexOf(s.Max());
			s[maxInd] --;
			if (val(s))
				return "" + alphabet(maxInd);
			var maxInd2 = s.IndexOf(s.Max());
			s[maxInd2]--;
			Debug.Assert(val(s));
			return "" + alphabet(maxInd) + alphabet(maxInd2);
		}

		static bool val(List<int> s)
		{
			var sum = s.Sum();
			return !s.Any(p => p > sum/2.0);
		}

		static char alphabet(int p)
		{
			return (char) (65 + p);
		}
	}
}
