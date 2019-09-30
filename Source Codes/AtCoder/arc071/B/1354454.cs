using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
		long mod = 1000000000 + 7;
		this.xList = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        long yoko = 0;
        for (int i = 1; i < xList.Length; i++) {
            yoko += (xList[i] - xList[i - 1]) % mod * i % mod * (xList.Length - i) % mod;
            yoko = yoko % mod;
        }
        this.yList = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        long tate = 0;
        for (int i = 1; i < yList.Length; i++)
		{
            tate += (yList[i] - yList[i - 1]) % mod * i % mod * (yList.Length - i) % mod;
            tate = tate % mod;
		}

        long ans = yoko * tate % mod;
        Console.WriteLine(ans);
    }

    private long[] xList;
    private long[] yList;


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


3 3
1 3 4
1 3 6



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