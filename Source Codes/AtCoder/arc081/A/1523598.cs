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
        long[] sticklist = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

        long max1 = 0;
        long max2 = 0;
        Dictionary<long, int> stickDic = new Dictionary<long, int>();

        sticklist.ToList().ForEach(a=>{
            if(stickDic.ContainsKey(a)) {
                stickDic[a]++;
                if(stickDic[a]>=4) {
                    if(a>max1) {
                        max1 = a;
                        max2 = a;
                    } else if(a>max2) {
                        max2 = a;
                    }
                } else {
					if (a > max1)
					{
                        max2 = max1;
						max1 = a;
					}
                    else if (a > max2 && a!=max1)
					{
						max2 = a;
					}
				}
            } else {
                stickDic[a] = 1;
            }
        });
        long ans = max1 * max2;
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
3 3 3 3 4 4 4 5 5 5


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