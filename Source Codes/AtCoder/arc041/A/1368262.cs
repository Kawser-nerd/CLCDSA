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

        int omote = inpt[0];
        int ura = inpt[1];


        int turn = int.Parse(Reader.ReadLine());

        int turnUra = Math.Min(turn, ura);
        int turnOmote = turn - turnUra;

        ura -= turnUra;
        omote += turnUra;

        omote -= turnOmote;
        ura += turnOmote;


        Console.WriteLine(omote);
        


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


3 2
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