using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Program
{

    public void Proc()
    {
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        string ans = "Alice";
        if(Math.Abs(inpt[0]-inpt[1])<=1) {
            ans = "Brown";
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


5 0

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