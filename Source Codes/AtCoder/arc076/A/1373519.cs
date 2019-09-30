using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
        if(Math.Abs(inpt[0]-inpt[1])>=2) {
            Console.WriteLine(0);
            return;
        }
        long ans = 1;
        long mod = 1000000000 + 7;
        for (int i = 0; i < inpt[0]; i++) {
            ans = ans * (inpt[0] - i);
            ans = ans % mod;
        }
        for (int i = 0; i < inpt[1]; i++) {
            ans = ans * (inpt[1] - i);
            ans = ans % mod;
        }
        if(inpt[0]==inpt[1]) {
            ans = ans * 2;
            ans = ans % mod;
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




100000 100000


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