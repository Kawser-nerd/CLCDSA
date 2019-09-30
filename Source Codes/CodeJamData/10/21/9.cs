using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
	class Program
	{
		class Dir
		{
			public Dictionary<string, Dir> subdirs = new Dictionary<string, Dir>();
		}

		static int regdir(string[] path, int index, Dir root) {

			if (index >= path.Length)
				return 0;

			if (root.subdirs.ContainsKey(path[index]))
				return regdir(path, index+1, root.subdirs[path[index]]);
			else {
				root.subdirs[path[index]] = new Dir();
				return 1+regdir(path, index+1, root.subdirs[path[index]]);
			}
		}

		static void Test(int testcase) {
			Console.Write("Case #{0}: ", testcase);

			string[] words = Console.ReadLine().Split(' ');

			int N = int.Parse(words[0]);
			int M = int.Parse(words[1]);

			Dir root = new Dir();

			for (int i = 0; i < N; i++)
				regdir(Console.ReadLine().Split('/'), 1, root);

			int sum = 0;
			for (int i = 0; i < M; i++)
				sum += regdir(Console.ReadLine().Split('/'), 1, root);

			Console.WriteLine(sum);
		}

		static void Main(string[] args) {
			int T = int.Parse(Console.ReadLine());
			for (int i = 1; i <= T; i++)
				Test(i);
		}
	}
}
