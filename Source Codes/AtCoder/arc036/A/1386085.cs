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
        int itemCount = inpt[0];
        int suimin = inpt[1];

        int[] suiminList = new int[itemCount];
        int ans = -1;
        for (int i = 0; i < itemCount; i++) {
            suiminList[i] = int.Parse(Reader.ReadLine());
            if(ans < 0 && i>=2) {
                int subtotal = suiminList[i - 2] + suiminList[i - 1] + suiminList[i];
                if(subtotal < suimin) {
                    ans = i + 1;
                }
            }
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



5 4230
360
360
360
360
360



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