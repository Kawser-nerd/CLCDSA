using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        string inpt = Reader.ReadLine();
        string ans = "YES";
        for (int i = 0; i < inpt.Length / 2; i++) {
            int c1 = inpt[i];
            int c2 = inpt[inpt.Length - i - 1];
            if(c1==c2) {
                continue;
            }
            if(c1=='*'||c2=='*') {
                continue;
            }
            ans = "NO";
            break;
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


a*bc*



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