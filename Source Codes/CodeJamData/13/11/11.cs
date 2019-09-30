using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			int N = int.Parse(Console.ReadLine());

			for (int i = 0; i < N; i++)
			{
				string[] s = Console.ReadLine().Split(' ');
				BigInteger r = BigInteger.Parse(s[0]);
				BigInteger t = BigInteger.Parse(s[1]);

				BigInteger b = (2 * r - 1);
				BigInteger k = ((-b + SqRtN(b * b + 8 * t)) / 4);


				Console.WriteLine("Case #{0}: {1}", i + 1, k);
			}
		}

		public static BigInteger SqRtN(BigInteger N)
		{
			/*++
			 *  Using Newton Raphson method we calculate the
			 *  square root (N/g + g)/2
			 */
			BigInteger rootN = N;
			int bitLength = 1; // There is a bug in finding bit length hence we start with 1 not 0
			while (rootN / 2 != 0)
			{
				rootN /= 2;
				bitLength++;
			}
			bitLength = (bitLength + 1) / 2;
			rootN = N >> bitLength;

			BigInteger lastRoot = BigInteger.Zero;
			do
			{
				lastRoot = rootN;
				rootN = (BigInteger.Divide(N, rootN) + rootN) >> 1;
			}
			while (!((rootN ^ lastRoot).ToString() == "0"));
			return rootN;
		} // SqRtN
	}
}
