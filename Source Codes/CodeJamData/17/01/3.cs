using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Test
{
	class Program
	{
		StreamReader sr;
		StreamWriter sw;
		void run()
		{
			String[] inp = sr.ReadLine().Split(' ');
			int k = Convert.ToInt32(inp[1]);
			char[] s = inp[0].ToCharArray();
			int n = s.Length, res = 0;
			for(int i=0; i+k<=n; i++)
				if (s[i] == '-')
				{
					++res;
					for (int j = 0; j < k; j++)
						s[i+j] = Convert.ToChar('+' + '-' - s[i+j]);
				}
			bool flag = true;
			for (int i = n - k + 1; i < n; i++)
				if (s[i] == '-')
					flag = false;
			if (!flag)
				sw.WriteLine("IMPOSSIBLE");
			else
				sw.WriteLine(res);
		}
		void multiRun()
		{
			sr = new StreamReader("F:\\a.in");
			sw = new StreamWriter("F:\\a.out");
			int nTest = Convert.ToInt32(sr.ReadLine());
			for (int T = 1; T <= nTest; T++)
			{
				sw.Write("Case #" + Convert.ToString(T)+": ");
				run();
			}
			sr.Close();
			sw.Close();
		}
		static void Main(string[] args)
		{
			new Program().multiRun();
		}
	}
}