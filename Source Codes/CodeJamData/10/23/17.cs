using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using Library;
using Library.Extensions;
using System.Text;
using System.IO;

namespace WindowsFormsApplication1
{
	static class Program
	{
		[STAThread]
		static void Main()
		{
			string[] lines = System.IO.File.ReadAllLines(@"C:\Pub\C-small-attempt1.in");
			int caseN = 1;
			var sb = new StringBuilder();

			Dictionary<int, long> ss = new Dictionary<int, long>();

			for (int i = 1; i < lines.Length; i++)
			{
				int N = int.Parse(lines[i]);

				// {n}
				// {2,n}
				// {2,3,n}
				// {3,4,n}
				// {2,3,4,n}
				long cnt = 0;

				if (ss.ContainsKey(N))
				{
					cnt = ss[N];
				}

				if (cnt == 0)
				{
					int allCombo = 1 << N;
					int large = 1 << (N - 1);

					for (int j = 1; j < allCombo; j ++)
					{
						if ((j & large) != large) continue;
						if ((j & 1) == 1) continue;
						List<int> items = new List<int>();

						int current = 1;
						int tmp = j;
						while (tmp > 0)
						{
							if ((tmp & 1) == 1)
							{
								items.Add(current);
							}

							current++;
							tmp = tmp >> 1;
						}

						if (IsValid(items))
						{
							cnt++;
						}
					}

					ss[N] = cnt % 100003;

					cnt = cnt % 100003;
				}

				sb.AppendFormat("Case #{0}: {1}\r\n", caseN++, cnt);
			}

			string haha = sb.ToString();
			File.WriteAllText(@"C:\Pub\small.txt", sb.ToString());
		}

		public static bool IsValid(List<int> items)
		{
			int index = items.Count - 1;
			while (index > 0)
			{
				index = items.IndexOf(index+1);
			}

			return index != -1;
		}

		

	}
}
