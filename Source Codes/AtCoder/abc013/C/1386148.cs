using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC013
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			new MainClass().solve();
		}
		Scanner cin;
        const long INF = long.MaxValue;

        long N, H, A, B, C, D, E;

        //int X, Y;
        long MIN;

		void solve()
		{
			cin = new Scanner();
            N = cin.nextLong();
            H = cin.nextLong();
            A = cin.nextLong();
            B = cin.nextLong();
            C = cin.nextLong();
            D = cin.nextLong();
            E = cin.nextLong();

            MIN = INF;

            for (long i = 0; i <= N; i++){
                long tmp = poorMin(i);
                MIN = Math.Min(MIN, A*i+C*tmp);
            }

            Console.WriteLine(MIN);
		}
        long poorMin(long x){
            if (((N - x) * E - H - B * x) < 0)
                return 0;
			long y = ((N - x) * E - H - B * x) / (D + E) + 1;
            return(y > 0) ? y : 0;
        }

	}
	class Scanner
	{
		string[] nextBuffer;
		int BufferCnt;
		char[] cs = new char[] { ' ' };
		public Scanner()
		{
			nextBuffer = new string[0];
			BufferCnt = 0;
		}
		public string next()
		{
			if (BufferCnt < nextBuffer.Length)
				return nextBuffer[BufferCnt++];
			string st = Console.ReadLine();
			while (st == "")
				st = Console.ReadLine();
			nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			BufferCnt = 0;
			return nextBuffer[BufferCnt++];
		}
		public int nextInt()
		{
			return int.Parse(next());
		}
		public long nextLong()
		{
			return long.Parse(next());
		}
		public double nextDouble()
		{
			return double.Parse(next());
		}
	}
}