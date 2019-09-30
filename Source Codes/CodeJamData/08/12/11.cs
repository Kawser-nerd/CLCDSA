using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
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
			int C = int.Parse(first);
			for (int casen = 1; casen <= C; casen++)
			{
				string sec = input.ReadLine();
				int N = int.Parse(sec);
				string tir = input.ReadLine();
				int M = int.Parse(tir);

				bool?[] res = new bool?[N + 1];
				List<Cust> custs = new List<Cust>();
				for (int i = 0; i < M; i++)
				{
					string fss = input.ReadLine();
					string[] fs = fss.Split(' ');
					int T = int.Parse(fs[0]);
					Cust c = new Cust();
					c.flavs = new List<Flav>();
					custs.Add(c);
					for (int favi = 0; favi < T; favi++)
					{
						int fli = int.Parse(fs[1 + favi * 2]);
						bool flm = (int.Parse(fs[2 + favi * 2]) == 1);
						Flav f = new Flav(fli, flm);
						if (flm)
							c.flavs.Add(f);
						else
							c.flavs.Insert(0, f);
					}
				}

				custs.Sort(delegate(Cust c1, Cust c2) { return c1.flavs.Count.CompareTo(c2.flavs.Count); });
/*				while (custs.Count > 0 && custs[0].flavs.Count == 1)
				{
					res[f.n] = f.m;
					custs.RemoveAt(0);
				}
*/
				bool fail = !Tr(res, custs);

				if (fail)
				{
					output.WriteLine("Case #{0}: {1}", casen, "IMPOSSIBLE");
				}
				else
				{
					output.Write("Case #{0}:", casen);
					for (int i = 1; i <= N; i++)
					{
						if (!res[i].HasValue)
							output.Write(" {0}", 0);
						else
							output.Write(" {0}", res[i].Value ? 1 : 0);
					}
					output.WriteLine();
				}
			}
		}

		static bool Tr(bool?[] res, List<Cust> cuss)
		{
			if (cuss.Count == 0)
				return true;
			Cust c = cuss[0];
			cuss.RemoveAt(0);

			foreach (Flav f in c.flavs)
				if (!res[f.n].HasValue)
				{
					res[f.n] = f.m;
					if (Tr(res, cuss))
						return true;
					res[f.n] = null;
				}
				else if (res[f.n].Value == f.m)
				{
					if (Tr(res, cuss))
						return true;
				}
/*				else
				{
					bool orig = res[f.n].Value;
					res[f.n] = f.m;
					if (Tr(res, cuss))
						return true;
					res[f.n] = orig;
				}*/

			cuss.Insert(0, c);
			return false;
		}

		struct Cust
		{

			public List<Flav> flavs;
		}
		struct Flav
		{
			public Flav(int n, bool m)
			{
				this.n = n;
				this.m = m;
			}
			public int n;
			public bool m;
		}
	}
}
