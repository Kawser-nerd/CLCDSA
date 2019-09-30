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
		bool chk(char[] a)
		{
			for (int i = 0; i + 1 < a.Length; i++)
				if (a[i] > a[i + 1])
					return false;
			return true;
		}
		void run()
		{
			String s = sr.ReadLine();
			if (chk(s.ToCharArray()))
			{
				sw.WriteLine(s);
				return;
			}
			for (int i = s.Length - 1; i >= 0; i--)
			{
				if (s[i] == '0') continue;
				char[] a = s.ToCharArray();
				--a[i];
				for (int j = i + 1; j < s.Length; j++)
					a[j] = '9';
				if (chk(a))
				{
					String ss = new String(a).TrimStart("0".ToCharArray());
					sw.WriteLine(Convert.ToInt64(ss));
					return;
				}
			}
		}
		void multiRun()
		{
			sr = new StreamReader("F:\\a.in");
			sw = new StreamWriter("F:\\a.out");
			int nTest = Convert.ToInt32(sr.ReadLine());
			for (int T = 1; T <= nTest; T++)
			{
				sw.Write("Case #" + Convert.ToString(T) + ": ");
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