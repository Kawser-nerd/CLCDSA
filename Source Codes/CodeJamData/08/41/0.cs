using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace BooleanTree
{
	class Program
	{
		static void Main(string[] args)
		{
//			StreamReader sr = new StreamReader(@"c:\temp\a.in");
//			StreamReader sr = new StreamReader(@"c:\temp\a-small-attempt0.in");
			StreamReader sr = new StreamReader(@"c:\temp\a-large.in");
//			TextWriter tw = Console.Out;
			StreamWriter tw = new StreamWriter(@"c:\temp\alarge.out");

			int INF = 100000000;

			int noCases = int.Parse(sr.ReadLine());
			for(int caseNo = 1; caseNo <= noCases; caseNo++)
			{
				string[] line = sr.ReadLine().Split(' ');
				int M = int.Parse(line[0]), V = int.Parse(line[1]);
				int noInterior = (M - 1)/2;
				bool[] canChange = new bool[noInterior];
				bool[] andGate = new bool[noInterior];
				for (int i = 0; i < noInterior; i++)
				{
					line = sr.ReadLine().Split(' ');
					andGate[i] = line[0] == "1";
					canChange[i] = line[1] == "1";
				}
				int[] values = new int[M];
				int[] min0Changes = new int[M], min1Changes = new int[M];
				for (int i = noInterior; i < M; i++)
				{
					values[i] = int.Parse(sr.ReadLine());
					min0Changes[i] = values[i] == 0 ? 0 : INF;
					min1Changes[i] = values[i] == 1 ? 0 : INF;
				}

				for (int i = noInterior - 1; i >= 0; i--)
				{
					int leftChild = i*2+1, rightChild = i*2 + 2;
					
					int orChanges = andGate[i] ? (canChange[i] ? 1 : INF) : 0;
					int andChanges = andGate[i] ? 0 : (canChange[i] ? 1 : INF);

					int z1 = min0Changes[leftChild] + min0Changes[rightChild] + orChanges;
					int z2 = min0Changes[leftChild] + min0Changes[rightChild] + andChanges;
					int z3 = min1Changes[leftChild] + min0Changes[rightChild] + andChanges;
					int z4 = min0Changes[leftChild] + min1Changes[rightChild] + andChanges;

					int o1 = min1Changes[leftChild] + min1Changes[rightChild] + andChanges;
					int o2 = min0Changes[leftChild] + min1Changes[rightChild] + orChanges;
					int o3 = min1Changes[leftChild] + min0Changes[rightChild] + orChanges;
					int o4 = min1Changes[leftChild] + min1Changes[rightChild] + orChanges;

					int best0 = INF, best1 = INF;
					best0 = Math.Min(best0, Math.Min(z1, Math.Min(z2, Math.Min(z3, z4))));
					best1 = Math.Min(best1, Math.Min(o1, Math.Min(o2, Math.Min(o3, o4))));
					min0Changes[i] = best0;
					min1Changes[i] = best1;
				}

				tw.Write("Case #" + caseNo + ": ");
				int res = V == 0 ? min0Changes[0] : min1Changes[0];
				if (res >= INF)
					tw.WriteLine("IMPOSSIBLE");
				else
					tw.WriteLine(res);
			}

			tw.Close();
		}
	}
}
