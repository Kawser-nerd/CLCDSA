using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
		int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).OrderByDescending(a => a).ToArray();

		int ans = 0;
		while(inpt.Distinct().Count() > 1) {
			if(inpt[0] == inpt[1]) {
				inpt[2] += 2;
			} else {
				inpt[1]++;
				inpt[2]++;
			}
			ans++;
			inpt = inpt.OrderByDescending(a => a).ToArray();
		}
		Console.WriteLine(ans);
	}

	public class Reader
    {
        static StringReader sr;
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


2 6 3


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