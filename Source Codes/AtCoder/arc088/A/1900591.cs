using System;
using System.Collections.Generic;
class some
{
	public static void Main()
	{
		string[]kk=Console.ReadLine().Split();
		long a=long.Parse(kk[0]);
		long b=long.Parse(kk[1]);
		int ret=1;
		while(true)
		{
			a*=2;
			
			if(a>b)
			break;
			ret++;
		}
		Console.WriteLine(ret);
							
	}
}