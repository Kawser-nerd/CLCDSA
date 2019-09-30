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
        int[] items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();

        List<int> tmp = new List<int>();
        for (int i = 0; i < items.Length; i++) {
            if(i%2==0) {
                tmp.Add(items[i]);
            } else {
                tmp.Insert(0, items[i]);
            }
        }
        if(itemCount%2!=0) {
            tmp.Reverse();
        }
        Console.WriteLine(string.Join(" ", tmp));
        

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




4
1 2 3 4



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