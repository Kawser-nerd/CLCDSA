using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
	class Program
	{
		static string A, B, K;
		static Int64[, , ,] _f;
		static Int32 n;

		static Int64 f(Int32 x, Int64 lessA, Int64 lessB, Int64 lessK)
		{
			if (_f[x, lessA, lessB, lessK] != -1)
				return _f[x, lessA, lessB, lessK];
			if (x == n)
			{
				return (lessA == 1 && lessB == 1&& lessK == 1) ? 1 : 0;
			}

			Int64 o = 0;

			Int64 tLessA, tLessB, tLessK;

			for (Int64 i = 0; i <= 1; ++i)
			{
				if (i > (A[x] - '0') && lessA == 0)
					continue;

				if (i < (A[x] - '0'))
				{
					tLessA = 1;
				}
				else
					tLessA = lessA;

				for (Int64 j = 0; j <= 1; ++j)
				{
					if (j > (B[x] - '0') && lessB == 0)
						continue;

					if (j < (B[x] - '0'))
					{
						tLessB = 1;
					}
					else
						tLessB = lessB;

					Int64 l = i & j;

					if (l > (K[x] - '0') && lessK == 0)
						continue;

					if (l < (K[x] - '0'))
					{
						tLessK = 1;
					}
					else
						tLessK = lessK;

					o += f(x + 1, tLessA, tLessB, tLessK);
				}
			}


			_f[x, lessA, lessB, lessK] = o;
			return o; 
		}


		static void Main(string[] args)
		{
			using (StreamReader reader = new StreamReader(@"j:\codejam\ConsoleApplication6\input.txt"))
			{
				using (StreamWriter writer = new StreamWriter(@"j:\codejam\ConsoleApplication6\output.txt"))
				{
					Int32 T = Int32.Parse(reader.ReadLine());
					for (Int32 test = 1; test <= T; ++test)
					{
						String[] str = reader.ReadLine().Split(' ');
						Int64 iA = Int64.Parse(str[0]);
						Int64 iB = Int64.Parse(str[1]);
						Int64 iK = Int64.Parse(str[2]);
						A = Convert.ToString(iA, 2);
						B = Convert.ToString(iB, 2);
						K = Convert.ToString(iK, 2);
						n = Math.Max(Math.Max(A.Length, B.Length), K.Length);

						while (A.Length < n) A = '0' + A;
						while (B.Length < n) B = '0' + B;
						while (K.Length < n) K = '0' + K;

						_f = new Int64[n + 1, 2,2,2];
						for (Int64 i = 0; i < n + 1; ++i)
							for (Int64 j = 0; j < 2; ++j)
								for (Int64 l = 0; l < 2; ++l)
									for (Int64 k = 0; k < 2; ++k)
										_f[i, j, l, k] = -1;

						Int64 answer = f(0, 0, 0, 0);

						writer.WriteLine("Case #" + test + ": " + answer);
					}
				}
			}
		}
	}
}
