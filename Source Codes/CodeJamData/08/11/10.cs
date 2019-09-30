using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			string currentDir = Directory.GetCurrentDirectory();

			foreach (string inFileName in Directory.GetFiles(currentDir, "*.in"))
			{
				FileInfo inFile = new FileInfo(inFileName);
				FileInfo outFile = new FileInfo(string.Format("{0}.out", inFile.FullName.Substring(0, inFile.FullName.Length - inFile.Extension.Length)));

				using (StreamReader reader = new StreamReader(inFile.FullName))
				using (StreamWriter writer = new StreamWriter(outFile.FullName))
					Solve(reader, writer);

				Console.Write(string.Format("Finished:{0} -> {1}\nHit enter.", inFile, outFile));
				Console.ReadLine();
			}
		}
		public static void Solve(StreamReader input, StreamWriter output)
		{
			string first = input.ReadLine();
			int N = int.Parse(first);
			for (int n = 1; n <= N; n++)
			{
				List<int> xs = new List<int>();
				List<int> ys = new List<int>();
				string second = input.ReadLine();
				int c = int.Parse(second);
				string[] xa = input.ReadLine().Split(' ');
				string[] ya = input.ReadLine().Split(' ');
				int smallXi = -1;
				int smallYi = -1;
				int bigXi = -1;
				int bigYi = -1;
				for (int i = 0; i < c; i++)
				{
					int x = int.Parse(xa[i]);
					int y = int.Parse(ya[i]);
					xs.Add(x);
					ys.Add(y);
				}

				xs.Sort();
				ys.Sort();
/*
				int tryc = 0;
				int suc = 0;
				int? t = null;
				while (suc < 2 && tryc < c)
				{
					int? t = Permute(c, xs, ys, t);
					tryc++;
					if (t != null)
						suc++;
				}
*/
				int z = 0;
				for (int i = 0; i < c; i++)
					z += xs[i] * ys[c - i - 1];
				output.WriteLine("Case #{0}: {1}", n, z);
			}
		}
		/*
		static int? Permute(int c, List<int> xs, List<int> ys, int? skip)
		{
			int smallXi = -1;
			int smallYi = -1;
			int bigXi = -1;
			int bigYi = -1;
			for (int i = 0; i < c; i++)
			{
				if (skip.HasValue && skip.Value == i)
					continue;
				if (smallXi == -1 || x < xs[smallXi])
					smallXi = i;
				if (smallYi == -1 || x < ys[smallYi])
					smallYi = i;
				if (bigXi == -1 || x > xs[smallXi])
					bigXi = i;
				if (bigYi == -1 || x > ys[smallYi])
					bigYi = i;
			}
			
		}
		*/
	}
}
