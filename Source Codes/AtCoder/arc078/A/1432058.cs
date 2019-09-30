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
        this.Items = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        long total = Items.Sum();
        long subtotal = Items[0];
        long ans = Math.Abs((total-subtotal)-subtotal);
        for (int i = 1; i < itemCount-1; i++) {
            subtotal += this.Items[i];
            ans = Math.Min(ans, Math.Abs((total-subtotal)-subtotal));
        }
        Console.WriteLine(ans);
    }



    private long[] Items;


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
 

2
10 -10

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