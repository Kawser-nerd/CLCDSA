using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Beresta
{

	class ContestIO : StreamWriter
	{
		public ContestIO(Stream streamIn, Stream streamOut) : base(streamOut, Encoding.ASCII, 8192) { Reader = new StreamReader(streamIn, Encoding.ASCII, false, 8192); }
		public ContestIO(string inputFilePath, string outputFilePath) : this(File.OpenRead(inputFilePath), File.OpenWrite(outputFilePath)) { }
		public ContestIO(string inputText) : this(new MemoryStream(Encoding.ASCII.GetBytes(inputText)), Console.OpenStandardOutput(8192)) { }
		public ContestIO() : this(Console.OpenStandardInput(8192), Console.OpenStandardOutput(8192)) { }
		//d.ToString("N12", CultureInfo.InvariantCulture).Replace(",", "")
		public StreamReader Reader;
		
		bool IsDigit(int c) { return c >= '0' && c <= '9'; }
		public long Read()
		{
			int c1 = 0, c;
			while (!IsDigit(c = Reader.Read())) { c1 = c; }
			long r = c - '0';
			while (IsDigit(c = Reader.Read()))
				r = r * 10 + c - '0';
			return c1 == '-' ? -r : r;
		}
		public long[] ReadArray(int size) { return Enumerable.Range(0, size).Select(v => Read()).ToArray(); }
	}

	class Outfit
	{
		public Outfit(int j, int p, int s)
		{
			J = j;
			P = p;
			S = s;
			Comb1 = J * 10 + P;
			Comb2 = J * 10 + S;
			Comb3 = P * 10 + S;
		}

		public int J;
		public int P;
		public int S;

		public int Comb1;
		public int Comb2;
		public int Comb3;
	}

	class CombTracker
	{
		public CombTracker(int k)
		{
			K = k;
			for (var i = 0; i < 100; i++)
			{
				Comb1Count.Add(i, 0);
				Comb2Count.Add(i, 0);
				Comb3Count.Add(i, 0);
			}
		}
		public int K;
		public int Count;
		public Dictionary<int, int> Comb1Count = new Dictionary<int, int>();
		public Dictionary<int, int> Comb2Count = new Dictionary<int, int>();
		public Dictionary<int, int> Comb3Count = new Dictionary<int, int>();
		public List<Outfit> Outfits = new List<Outfit>();

		public bool CanUse(Outfit of)
		{
			return Comb1Count[of.Comb1] < K && Comb2Count[of.Comb2] < K && Comb3Count[of.Comb3] < K;
		}
		public void Use(Outfit of)
		{
			Outfits.Add(of);
			Comb1Count[of.Comb1]++;
			Comb2Count[of.Comb2]++;
			Comb3Count[of.Comb3]++;
			Count++;
		}
		public void Undo(Outfit of)
		{
			if (Outfits[Count - 1] != of)
				throw new Exception();
			Outfits.RemoveAt(Count - 1);
			Comb1Count[of.Comb1]--;
			Comb2Count[of.Comb2]--;
			Comb3Count[of.Comb3]--;
			Count--;
		}
	}

	class Program
	{

		static void Main(string[] args)
		{
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1C_C\C-small-attempt0.in", @"D:\Contests\input\GCJ2016_R1C_C\C-small-attempt0.out"))
//            using (var io = new ContestIO(@"4
//1 1 1 10
//1 2 3 2
//1 1 3 2
//1 2 3 1"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var j = (int)io.Read();
					var p = (int)io.Read();
					var s = (int)io.Read();
					var k = (int)io.Read();

					var res = Solve(j, p, s, k);
					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res));
				}
			}

			//Console.ReadLine();
		}

		static string Solve(int j, int p, int s, int k)
		{
			BestCount = -1;
			BestList = null;

			var outfits = new List<Outfit>((int)(j * p * s));
			for (var v1 = 1; v1 <= j; v1++)
			{
				for (var v2 = 1; v2 <= p; v2++)
				{
					for (var v3 = 1; v3 <= s; v3++)
					{
						outfits.Add(new Outfit(v1, v2, v3));
					}
				}
			}

			SolveReq(outfits, 0, new CombTracker(k));

			var sb = new StringBuilder();
			sb.AppendLine(BestCount.ToString());
			for (var i = 0; i < BestCount; i++)
			{
				var of = BestList[i];
				sb.Append(of.J);
				sb.Append(" ");
				sb.Append(of.P);
				sb.Append(" ");
				sb.Append(of.S);
				if (i != (BestCount - 1))
					sb.AppendLine();
			}

			return sb.ToString();
		}

		static int BestCount = -1;
		static List<Outfit> BestList = null;
		static void SolveReq(List<Outfit> outfits, int startIndex, CombTracker tracker)
		{
			if ((tracker.Count + outfits.Count - startIndex) < BestCount)
				return;

			bool flag = false;
			for (var i = startIndex; i < outfits.Count; i++)
			{
				var of = outfits[i];
				if (tracker.CanUse(of))
				{
					tracker.Use(of);
					SolveReq(outfits, i + 1, tracker);
					tracker.Undo(of);
					
					flag = true;
				}
			}

			if (!flag)
			{
				if (tracker.Count > BestCount)
				{
					BestCount = tracker.Count;
					BestList = new List<Outfit>(tracker.Outfits);
				}
			}
		}

	}

}
