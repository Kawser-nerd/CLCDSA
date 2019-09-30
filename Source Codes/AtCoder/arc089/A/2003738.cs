using System;
using System.Collections.Generic;
class some
{
	public static void Main()
	{
		int n=int.Parse(Console.ReadLine());
		int pt=0;
		int px=0;
		int py=0;
		bool yes=true;
		for(int i=0;i<n;i++)
		{
			string[]kk=Console.ReadLine().Split();
			int t=int.Parse(kk[0]);
			int x=int.Parse(kk[1]);
			int y=int.Parse(kk[2]);
			
			int dist=Math.Abs(x-px)+Math.Abs(y-py);
			if((t-pt)%2!=dist%2)
			{
				yes=false;
				break;
			}
			if(dist>t-pt)
			{
				yes=false;
				break;
			}						
			pt=t;
			px=x;
			py=y;
		}
		if(yes)Console.WriteLine("Yes");
		else Console.WriteLine("No");
	}
}