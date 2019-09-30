using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			new A().SolveAll();
		}
	}

	class A : Solver
	{
		static string[] Names = new string[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
		static int[,] _coeffs = new int[26, 10];
		static A()
		{
			for (var i = 0; i < Names.Length; i++)
			{
				for (var j = 0; j < Names[i].Length; j++)
				{
					_coeffs[Names[i][j] - 'A', i]++;
				}
			}
		}


		public override string SolveCase()
		{
			var S = RStr();
			var determinedCount = 0;
			var X = new int[10];
			var determined = new bool[10];

			while (determinedCount < 10)
			{
				var sum = new int[26];
				for (var i = 0; i < S.Length; i++)
				{
					sum[S[i] - 'A']++;
				}

				for (var c = 0; c < 26; c++)
				{
					for (var d = 0; d < 10; d++)
					{
						if (determined[d])
						{
							sum[c] -= X[d] * _coeffs[c, d];
						}
					}
				}

				bool anyDetermined = false;
				for (var c = 0; c < 26; c++)
				{
					for (var d = 0; d < 10; d++)
					{
						if (sum[c] == 0 && _coeffs[c, d] != 0)
						{
							if (!determined[d])
							{
								anyDetermined = true;
								determined[d] = true;
								determinedCount++;
								X[d] = 0;
							}
						}
					}
				}
				if (anyDetermined)
				{
					continue;
				}

				var system = new int[26, 11];
				for (var c = 0; c < 26; c++)
				{
					for (var d = 0; d < 10; d++)
					{
						if (determined[d])
						{
							continue;
						}
						system[c, d] = _coeffs[c, d];
					}
					system[c, 10] = sum[c];
				}

				int l = -1;
				for (var c = 0; c < 26; c++)
				{
					var nonZeroCount = 0;
					var digit = -1;
					for (var d = 0; d < 10; d++)
					{
						if (system[c, d] != 0)
						{
							nonZeroCount++;
							digit = d;
						}
					}
					if (nonZeroCount == 1)
					{
						X[digit] = system[c, 10] / system[c, digit];
						determined[digit] = true;
						determinedCount++;
						break;
					}
				}
			}

			var num = "";
			for (var i = 0; i < 10; i++)
			{
				for (var j = 0; j < X[i]; j++)
				{
					num += i.ToString();
				}
			}
			return num;

		}
	}

	abstract class Solver
	{
		public FileStream _inFile, _outFile;
		public StreamReader _reader;
		public StreamWriter _writer;
		public Queue<string> _readQ = new Queue<string>();

		public void SolveAll()
		{
			_inFile = new FileStream(GetType().Name + ".in", FileMode.Open, FileAccess.Read);
			_reader = new StreamReader(_inFile);
			_outFile = new FileStream(GetType().Name + ".out", FileMode.Create, FileAccess.Write);
			_writer = new StreamWriter(_outFile);
			var T = RInt();
			for (var t = 1; t <= T; t++)
			{
				_writer.WriteLine($"Case #{t}: {SolveCase()}");
			}
			_writer.Flush();
			_writer.Close();
		}

		public abstract string SolveCase();

		public virtual char[] GetSeparators()
		{
			return new char[] { ' ' };
		}

		public int RInt()
		{
			EnsureQ();
			return int.Parse(_readQ.Dequeue());
		}

		public long RLong()
		{
			EnsureQ();
			return long.Parse(_readQ.Dequeue());
		}

		public string RStr()
		{
			EnsureQ();
			return _readQ.Dequeue();
		}

		private void EnsureQ()
		{
			if (_readQ.Count == 0)
			{
				var s = _reader.ReadLine();
				foreach (var part in s.Split(GetSeparators()))
				{
					_readQ.Enqueue(part);
				}
			}
		}
	}
}
