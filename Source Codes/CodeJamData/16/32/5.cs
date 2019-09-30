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

	class Program
	{

		static void Main(string[] args)
		{
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1C_B\B-large.in", @"D:\Contests\input\GCJ2016_R1C_B\B-large.out"))
//            using (var io = new ContestIO(@"6
//5 4
//2 1
//4 20
//5 7
//5 9
//6 16"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var b = io.Read();
					var m = io.Read();

					var res = Solve(b, m);
					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res));
				}
			}

			//Console.ReadLine();
		}

		static string Solve(long b, long m)
		{
			var result = new bool[b, b];
			for (var i = 0; i < b - 1; i++)
				result[i, i + 1] = true;

			if (m == 1)
			{
				return FormatResult(result, b);
			}
			else
			{
				var count = m;

				var ways = new long[b];
				ways[b - 1] = 0;
				var waysCount = 1L;
				for (var i = b - 2; i >= 0; i--)
				{
					ways[i] = waysCount;
					waysCount *= 2L;
				}

				if (count > ways[0])
					return "IMPOSSIBLE";

				var first = -1;
				for (var i = 0; i < b; i++)
				{
					if (ways[i] <= count)
					{
						first = i;
						break;
					}
				}

				for (var i = first; i < b; i++)
				{
					for (var j = i + 1; j < b; j++)
					{
						result[i, j] = true;
					}
				}
				count -= ways[first];

				while (count > 0)
				{
					var next = -1;
					for (var i = 0; i < b; i++)
					{
						if (ways[i] <= count)
						{
							next = i;
							break;
						}
					}
					result[0, next] = true;
					count -= ways[next];
				}

				return FormatResult(result, b);
			}
		}

		static string FormatResult(bool[,] result, long b)
		{
			var sb = new StringBuilder();
			sb.AppendLine("POSSIBLE");
			for (var i = 0; i < b; i++)
			{
				for (var j = 0; j < b; j++)
				{
					sb.Append(result[i, j] ? '1' : '0');
				}

				if (i != (b - 1))
					sb.AppendLine();
			}
			return sb.ToString();
		}

	}

}
