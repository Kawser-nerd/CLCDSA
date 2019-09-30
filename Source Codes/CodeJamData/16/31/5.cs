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
			using (var io = new ContestIO(@"D:\Contests\input\GCJ2016_R1C_A\A-large.in", @"D:\Contests\input\GCJ2016_R1C_A\A-large.out"))
//            using (var io = new ContestIO(@"4
//2
//2 2
//3
//3 2 2
//3
//1 1 2
//3
//2 3 1"))
			{
				var t = io.Read();
				for (var i = 0; i < t; i++)
				{
					var n = (int)io.Read();
					var arr = io.ReadArray(n);

					var res = Solve(n, arr);
					io.WriteLine(string.Format("Case #{0}: {1}", (i + 1), res));
				}
			}

			//Console.ReadLine();
		}

		static string Solve(int n, long[] arr)
		{
			var count = arr.Sum();
			var sb = new StringBuilder();

			while (count > 0)
			{
				long max = -1;
				int p1 = -1, p2 = -1;
				for (var i = 0; i < n; i++)
				{
					if (arr[i] > max)
					{
						p1 = i;
						p2 = -1;
						max = arr[i];
					}
					else if (arr[i] == max)
					{
						if (p2 == -1)
							p2 = i;
					}
				}

				if (p2 == -1)
				{
					var ch = ToChar(p1);
					sb.Append(ch);
					sb.Append(ch);
					sb.Append(" ");
					arr[p1] -= 2;
					count -= 2;
				}
				else
				{
					var half = (count - 2) / 2;
					bool flag = true;
					for (var i = 0; i < n; i++)
					{
						if (i == p1 || i == p2)
						{
							if ((arr[i] - 1) > half)
							{
								flag = false;
								break;
							}
						}
						else
						{
							if (arr[i] > half)
							{
								flag = false;
								break;
							}
						}
					}

					if (flag)
					{
						var ch1 = ToChar(p1);
						var ch2 = ToChar(p2);
						sb.Append(ch1);
						sb.Append(ch2);
						sb.Append(" ");
						arr[p1] -= 1;
						arr[p2] -= 1;
						count -= 2;
					}
					else
					{
						var ch1 = ToChar(p1);
						sb.Append(ch1);
						sb.Append(" ");
						arr[p1] -= 1;
						count -= 2;
					}
				}
			}

			return sb.ToString();
		}

		static char ToChar(int i)
		{
			return (char)('A' + i);
		}

	}

}
