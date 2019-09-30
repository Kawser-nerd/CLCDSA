using System;

namespace ABC058_B
{
	internal class Program
	{
		public static void Main(string[] args)
		{
			string o = Console.ReadLine();
			string e = Console.ReadLine();

			string resultStr = "";
			int count = 0;
			for (int i = 0; i < e.Length;)
			{
				if (count % 2 == 0)
				{
					resultStr += o.Substring(i, 1);
				}
				else
				{
					resultStr += e.Substring(i, 1);
					i++;
				}

				count++;
			}

			if (o.Length - e.Length == 1) 
				resultStr += o.Substring(o.Length - 1, 1);
			
			Console.WriteLine(resultStr);
		}
	}
}