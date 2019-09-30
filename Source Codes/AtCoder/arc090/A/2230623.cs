using System;
using System.Linq;
using System.Collections.Generic;
public class Test
{
	public static void Main()
	{
		int n=int.Parse(Console.ReadLine());
		int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
		int []b=Console.ReadLine().Split().Select(int.Parse).ToArray();
		int max=int.MinValue;
		for(int i=0;i<n;i++){int h=0;
			for(int j=0;j<=i;j++){
				h+=a[j];
			}
			for(int j=i;j<n;j++){
				h+=b[j];
			}
			max=Math.Max(h,max);
		}
Console.WriteLine(max);
		
	}
}