using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class C
{
	
	public static void Main()
	{	
		int N = Int32.Parse(Console.ReadLine());
		
		int[] x = new int[N];
		int[] y = new int[N];
		int[] h = new int[N];
		for(int i = 0; i < N; i++)
		{
			string[] args = Console.ReadLine().Split(' ');
			x[i] = Int32.Parse(args[0]);
			y[i] = Int32.Parse(args[1]);
			h[i] = Int32.Parse(args[2]);
		}
		
		int iPlus = -1;
		for(int i = 0; i < N; i++)
		{
			if(h[i] > 0)
			{
				iPlus = i;
				break;
			}
		}
		
		for(int Cx = 0; Cx <= 100; Cx++)
		{
			for(int Cy = 0; Cy <= 100; Cy++)
			{
				bool correct = true;
				int H = h[iPlus] + Math.Abs(x[iPlus] - Cx) + Math.Abs(y[iPlus] - Cy);
				for(int i = iPlus + 1; i < N; i++)
				{
					if(h[i] == 0)
						continue;  // next i
					
					if(h[i] + Math.Abs(x[i] - Cx) + Math.Abs(y[i] - Cy) != H)
					{
						correct = false;
						break;  // end i-loop
					}
				}
				if(!correct)
					continue;  // next Cy
				
				for(int i = 0; i < N; i++)
				{
					if(h[i] != 0)
						continue;  // next i
					
					if(H > Math.Abs(x[i] - Cx) + Math.Abs(y[i] - Cy))
					{
						correct = false;
						break;  // end i-loop
					}					
				}
				
				if(correct)
				{
					Console.WriteLine("{0} {1} {2}", Cx, Cy, H);
					return;
				}				
			}		
		}
	}	
}