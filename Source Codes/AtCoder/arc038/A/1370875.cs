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
        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).OrderByDescending(a => a).ToArray();
        int ans = 0;
        for (int i = 0; i < items.Length; i+=2) {
            ans += items[i];
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



5
2 5 9 6 5



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