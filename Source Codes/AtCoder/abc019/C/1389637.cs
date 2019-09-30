using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC019
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			new MainClass().solve();
		}
		Scanner cin;

        int N;
        HashSet<int> a;
		void solve()
		{
            cin = new Scanner();

            N = cin.nextInt();

            a = new HashSet<int>();

            for (int i = 0; i < N;i++){
                a.Add(cin.nextInt());
            }

            int[] aa = a.ToArray();
            HashSet<int> origin = new HashSet<int>();

            for (int i = 0; i < aa.Length;i++){
                int tmp=aa[i];
                while(tmp%2==0){
                    tmp /= 2;
                }
                origin.Add(tmp);
            }

            Console.WriteLine(origin.Count());

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