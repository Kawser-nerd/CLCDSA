using System;
using System.Collections.Generic;
//using System.Linq;
class Program
{
	static void Main(string[] args)
	{
		// ??????
        string[] input = Console.ReadLine().Split(' ');
				int N = int.Parse(input[0]);
				int M = int.Parse(input[1]);

				// M??????M/N???????

				// M??????
				int max = (int)Math.Sqrt(M);
				List<int> div = new List<int>();
				//div.Add(1);
				for(int i=1; i<= max; i++)
				{
					if(M%i == 0)
					{
						div.Add(i);
						div.Add(M/i);
					}
				}

				div.Sort();

				for(int i=div.Count - 1; i>=0; i--)
				{
					if(div[i] <= M/N)
					{
						Console.WriteLine(div[i] + "");
						break;
					}
				}
    }

		class point
		{
			public int x{set; get;}
			public int y{set; get;}
			public int h{set; get;}
		}
}