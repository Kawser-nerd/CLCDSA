using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;

namespace GCJ2015_Round2_C
{
	class ContestIO : IDisposable
	{
		const int BufferSize = 1024 * 8;
		const string DefaultFileName = "input.txt";

		StreamReader reader;
		StreamWriter writer;

		public ContestIO(string fileName = null)
		{
#if DEBUG
			var args = Environment.GetCommandLineArgs();
			if (args.Length > 1)
				fileName = args[1];
			else if (fileName == null)
				fileName = DefaultFileName;

			if (File.Exists(fileName))
			{
				reader = new StreamReader(File.OpenRead(fileName), Encoding.ASCII, false, BufferSize);

				var outFileName = fileName + ".out.txt";
				if (File.Exists(outFileName))
					File.Delete(outFileName);
				writer = new StreamWriter(File.OpenWrite(outFileName), Encoding.ASCII, BufferSize);
			}

			if (reader == null || writer == null)
			{
#endif
				reader = new StreamReader(Console.OpenStandardInput(BufferSize), Encoding.ASCII, false, BufferSize);
				writer = new StreamWriter(Console.OpenStandardOutput(BufferSize), Encoding.ASCII, BufferSize);
#if DEBUG
			}
#endif
		}

		bool IsDigit(int c)
		{
			return c >= '0' && c <= '9';
		}
		int Next()
		{
			return reader.Read();
		}

		public int Read()
		{
			int c = Next();
			while (!IsDigit(c))
			{
				c = Next();
			}
			int r = 0;
			while (IsDigit(c))
			{
				r = r * 10 + (c - '0');
				c = Next();
			}
			return r;
		}
		public long ReadL()
		{
			return (long)Read();
		}
		public int[] ReadList(int size)
		{
			var r = new int[size];
			for (var i = 0; i < size; i++)
				r[i] = Read();
			return r;
		}
		public long[] ReadListL(int size)
		{
			var r = new long[size];
			for (var i = 0; i < size; i++)
				r[i] = ReadL();
			return r;
		}
		public string ReadLine()
		{
			return reader.ReadLine();
		}
		public void ReadTrailNewLine()
		{
			while (reader.Peek() == '\n' || reader.Peek() == '\r')
				reader.Read();
		}

		public void Write(int v, bool newLine = true)
		{
			var c = newLine ? '\n' : ' ';
			writer.Write(v);
			writer.Write(c);
		}
		public void Write(long v, bool newLine = true)
		{
			var c = newLine ? '\n' : ' ';
			writer.Write(v);
			writer.Write(c);
		}
		public void Write(IEnumerable<int> arr, bool newLine = false)
		{
			var c = newLine ? '\n' : ' ';
			foreach (var v in arr)
			{
				writer.Write(v);
				writer.Write(c);
			}
			writer.WriteLine();
		}
		public void WriteLine(string text = "")
		{
			if (!string.IsNullOrEmpty(text))
				writer.Write(text);
			writer.Write('\n');
		}

		public void Dispose()
		{
			writer.Flush();
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			using (var io = new ContestIO("input.txt"))
			{
				var t = io.Read();
				io.ReadTrailNewLine();
				for (var i = 0; i < t; i++)
				{
					var n = io.Read();
					io.ReadTrailNewLine();
					
					Dictionary<string, int> hash = new Dictionary<string, int>();
					int idx = 0;
					var lines = new List<int[]>();
					
					for (var j = 0; j < n; j++)
					{
						var line = io.ReadLine().Split(' ').Select(s =>
						{
							if (hash.ContainsKey(s))
								return hash[s];
							hash.Add(s, idx);
							return idx++;
						}).ToArray();
						lines.Add(line);
					}
					Solve(io, i + 1, lines, hash, idx);
				}
			}

		}
		static void Solve(ContestIO io, int caseId, List<int[]> lines, Dictionary<string, int> hash, int wordsCount)
		{
			int[] en = new int[wordsCount];
			int[] fr = new int[wordsCount];
			Line(lines[0], en);
			Line(lines[1], fr);
			int result = int.MaxValue;
			SolveRec(lines, en, fr, 2, (r, f) => {
				if (f)
				{
					if (r < result)
					{
						result = r;
						return true;
					}
				}
				return r < result;
			});
			io.WriteLine(string.Format("Case #{0}: {1}", caseId, result));
		}
		static void SolveRec(List<int[]> lines, int[] en, int[] fr, int pos, Func<int, bool, bool> result)
		{
			if (pos % 10 == 0)
			{
				if (!result(EvalResult(en, fr), false))
					return;
			}
			if (pos == lines.Count)
			{
				result(EvalResult(en, fr), true);
			}
			else
			{
				var line = lines[pos];
				Line(line, en);
				SolveRec(lines, en, fr, pos + 1, result);
				LineUndo(line, en);
				Line(line, fr);
				SolveRec(lines, en, fr, pos + 1, result);
				LineUndo(line, fr);
			}
		}
		static void Line(int[] line, int[] lang)
		{
			for (var i = 0; i < line.Length; i++)
				lang[line[i]] += 1;
		}
		static void LineUndo(int[] line, int[] lang)
		{
			for (var i = 0; i < line.Length; i++)
				lang[line[i]] -= 1;
		}
		static int EvalResult(int[] en, int[] fr)
		{
			var res = 0;
			for (var i = 0; i < en.Length; i++)
			{
				if (en[i] > 0 && fr[i] > 0)
					res++;
			}
			return res;
		}
		
	}

}
