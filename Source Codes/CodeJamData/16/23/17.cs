using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			new C().SolveAll();
		}
	}

	class C : Solver
	{
		public override string SolveCase()
		{
			var N = RInt();
			string[] w1 = new string[N], w2 = new string[N];
			for (var i = 0; i < N; i++)
			{
				w1[i] = RStr();
				w2[i] = RStr();
			}
			var max = 0;
			var c = 1;
			for (var i = 0; i < N; i++)
			{
				max += c;
				c *= 2;
			}
			var maxFakes = 0;
			bool[] fake = new bool[N];
			for (var p = 0; p <= max; p++)
			{
				var q = p;
				int fales = 0;
				for (var i = 0; i < N; i++)
				{
					if (q % 2 == 1)
					{
						fake[i] = true;
						fales++;
					}
					else
					{ fake[i] = false; }

					q /= 2;
				}
				if(fales <= maxFakes)
				{
					continue;
				}
				var possible = true;
				for (var i = 0; i < N; i++)
				{
					if (!fake[i])
					{
						continue;
					}
					var foundFirst = false;
					var foundSecond = false;
					for (var j = 0; j < N; j++)
					{
						if (!fake[j])
						{
							if (w1[i] == w1[j])
							{
								foundFirst = true;
							}
							if (w2[i] == w2[j])
							{
								foundSecond = true;
							}
						}
					}
					if (!foundSecond || !foundFirst)
					{
						possible = false;
						break;
					}
				}
				if (possible)
				{
					maxFakes = fales;
				}
			}
			return maxFakes.ToString();
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
