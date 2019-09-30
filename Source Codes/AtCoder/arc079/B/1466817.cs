using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        long num = long.Parse(Reader.ReadLine());
        long[] ans = GetNum2(num);
        Console.WriteLine(50);
        Console.WriteLine(string.Join(" ", ans));
    }

    private long[] GetNum2(long num) {
        if (num == 0)
        {
            long[] tmp = new long[50];
            tmp = tmp.Select(a => (long)49).ToArray();
            tmp[49] = 0;
            return tmp;

        }
        if(num%50==0) {
            long[] tmp = GetNum2(0).Select(a=>a+num/50).ToArray();
            return tmp;
        } else {
            long[] tmp = GetNum2(num - 1).Select(a=>a-1).OrderBy(a=>a).ToArray();
            tmp[0] += 51;
            return tmp;
        }
    }

    private long[] GetNum(long num) {
        if(num == 0) {
            return new long[] { 1, 0 };
        }

        if (num % 2 == 0)
        {
            long[] tmp = GetNum(0).Select(a => a + num / 2).ToArray();
            return tmp;
        }
        else
        {
            long[] tmp = GetNum(num - 1);
            tmp[0]--;
            tmp[1] += 2;
            return tmp;
        }
                
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

1

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