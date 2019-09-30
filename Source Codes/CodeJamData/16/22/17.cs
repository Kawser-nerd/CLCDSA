using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			new B().SolveAll();
		}
	}

	class B : Solver
	{
		string C, J;
		char[] c, j;
		long bestC, bestJ;
		int Len;
		long bestDiff;
		char[] altC, altJ;
		long altBestC, altBestJ;
		long altBestDiff;

		public override string SolveCase()
		{
			C = RStr();
			J = RStr();

			c = C.ToArray();
			j = J.ToArray();

			Len = C.Length;

			bestDiff = long.MaxValue;
			altBestDiff = long.MaxValue;

			bestC = long.MaxValue;
			bestJ = long.MaxValue;

			altC = C.ToArray();
			altJ = J.ToArray();
			//Brute(0);

			SolveRecursive(0, 0);

			//if (altBestC != bestC || altBestJ != bestJ)
			//{

			//}

			return bestC.ToString().PadLeft(Len, '0') + " " + bestJ.ToString().PadLeft(Len, '0');
		}

		public void Brute(int loc)
		{
			if (loc == Len)
			{
				var cc = long.Parse(new string(altC));
				var jj = long.Parse(new string(altJ));
				if (Math.Abs(cc - jj) < altBestDiff)
				{
					altBestC = cc;
					altBestJ = jj;
					altBestDiff = Math.Abs(cc - jj);
				}
				else if (Math.Abs(cc - jj) == altBestDiff)
				{
					if (cc < altBestC)
					{
						altBestC = cc;
						altBestJ = jj;
						altBestDiff = Math.Abs(cc - jj);
					}
					else if (cc == altBestC && jj < altBestJ)
					{
						altBestC = cc;
						altBestJ = jj;
						altBestDiff = Math.Abs(cc - jj);
					}
				}
				return;
			}
			if (C[loc] != '?' && J[loc] != '?')
			{
				Brute(loc + 1);
			}
			else if (C[loc] == '?' && J[loc] != '?')
			{
				for (var c = '0'; c <= '9'; c++)
				{
					altC[loc] = c;
					Brute(loc + 1);
				}
			}
			else if (C[loc] != '?' && J[loc] == '?')
			{
				for (var c = '0'; c <= '9'; c++)
				{
					altJ[loc] = c;
					Brute(loc + 1);
				}
			}
			else if (C[loc] == '?' && J[loc] == '?')
			{
				for (var c1 = '0'; c1 <= '9'; c1++)
				{
					altC[loc] = c1;
					for (var c2 = '0'; c2 <= '9'; c2++)
					{
						altJ[loc] = c2;
						Brute(loc + 1);
					}
				}
			}
			else
			{

			}
		}

		private void SolveRecursive(int loc, int sign)
		{
			if (loc == Len)
			{
				var cc = long.Parse(new string(c));
				var jj = long.Parse(new string(j));
				if (Math.Abs(cc - jj) < bestDiff)
				{
					bestC = cc;
					bestJ = jj;
					bestDiff = Math.Abs(cc - jj);
				}
				return;
			}
			if (C[loc] != '?' && J[loc] != '?')
			{
				var newSign = sign;
				if (newSign == 0)
				{
					newSign = C[loc].CompareTo(J[loc]);
				}
				SolveRecursive(loc + 1, newSign);
				return;
			}
			if (sign > 0)
			{
				if (C[loc] == '?')
				{
					c[loc] = '0';
				}
				if (J[loc] == '?')
				{
					j[loc] = '9';
				}
				SolveRecursive(loc + 1, sign);
				return;
			}
			else if (sign < 0)
			{
				if (C[loc] == '?')
				{
					c[loc] = '9';
				}
				if (J[loc] == '?')
				{
					j[loc] = '0';
				}
				SolveRecursive(loc + 1, sign);
				return;
			}
			else
			{
				if (C[loc] == '?')
				{
					if (J[loc] == '?')
					{
						c[loc] = '0';
						j[loc] = '0';
						SolveRecursive(loc + 1, sign);

						c[loc] = '0';
						j[loc] = '1';
						SolveRecursive(loc + 1, sign == 0 ? -1 : sign);

						c[loc] = '1';
						j[loc] = '0';
						SolveRecursive(loc + 1, sign == 0 ? 1 : sign);
					}
					else
					{
						if (J[loc] > '0')
						{
							c[loc] = (char)(J[loc] - 1);
							SolveRecursive(loc + 1, sign == 0 ? -1 : sign);
						}
						c[loc] = J[loc];
						SolveRecursive(loc + 1, sign);
						if (J[loc] < '9')
						{
							c[loc] = (char)(J[loc] + 1);
							SolveRecursive(loc + 1, sign == 0 ? 1 : sign);
						}
					}
				}
				else
				{
					if (C[loc] > '0')
					{
						j[loc] = (char)(C[loc] - 1);
						SolveRecursive(loc + 1, sign == 0 ? 1 : sign);
					}
					j[loc] = C[loc];
					SolveRecursive(loc + 1, sign);
					if (C[loc] < '9')
					{
						j[loc] = (char)(C[loc] + 1);
						SolveRecursive(loc + 1, sign == 0 ? -1 : sign);
					}
				}
			}
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
			var T = RLong();
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

		public int Rint()
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
