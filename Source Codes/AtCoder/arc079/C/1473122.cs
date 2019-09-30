using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int itemCount = int.Parse(Reader.ReadLine());
        long[] tmp = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderByDescending(a=>a).ToArray();
        long ans = 0;

        while(tmp[0]>itemCount-1 && tmp[0]-tmp.Last()>=itemCount) {
			long diff = tmp[0] - (tmp.Length - 1);
            long div = diff / tmp.Length;
            if (diff % tmp.Length > 0)
			{
				div++;
			}
			tmp[0] -= (itemCount) * div;
            for (int i = 1; i < itemCount; i++) {
                tmp[i] += div;
            }
            ans += div;
            tmp = tmp.OrderByDescending(a => a).ToArray();
		}
        if(tmp.Last()>=itemCount) {
            long addAns = tmp.Last() - (itemCount - 1);
            tmp = tmp.Select(a => a - addAns).ToArray();
            ans += addAns*tmp.Length;
        }
        while(tmp[0]>itemCount-1) {
            tmp = tmp.Select(a => a + 1).ToArray();
            tmp[0] -= (itemCount + 1);
            tmp = tmp.OrderByDescending(a => a).ToArray();
            ans++;
        }
        Console.WriteLine(ans);

    }


    public class Reader
	{
		private static StringReader sr;
		public static bool IsDebug = false;
		public static string ReadLine()
		{
			if (IsDebug)
			{
				if (sr == null)
				{
					sr = new StringReader(InputText.Trim());
				}
				return sr.ReadLine();
			}
			else
			{
				return Console.ReadLine();
			}
		}
		private static string InputText = @"

10
1000 193 256 777 0 1 1192 1234567891011 48 425


";
	}

	public static void Main(string[] args)
	{
#if DEBUG
		Reader.IsDebug = true;
#endif
		Program prg = new Program();
		prg.Proc();
	}
}