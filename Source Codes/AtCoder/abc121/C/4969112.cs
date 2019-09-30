using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;


public class Store
{
	public long A { get; private set; }
	public long B { get; private set; }
	
	public Store(long a, long b)
	{
		A = a;
		B = b;
	}
}


public class C
{
	public static void Main()
	{
		string[] args;

		args = Console.ReadLine().Split(' ');
		int N = Int32.Parse(args[0]);
		int M = Int32.Parse(args[1]);
		
		List<Store> storeList = new List<Store>(N);
		for(int i = 0; i < N; i++)
		{
			args = Console.ReadLine().Split(' ');
			long a = Int32.Parse(args[0]);
			long b = Int32.Parse(args[1]);
			storeList.Add(new Store(a,b));
		}
		storeList.Sort((x,y) => (int)(x.A - y.A));
		
		long rest = M;
		long ans = 0;
		int index = 0;
		while(rest > 0)
		{
			Store current = storeList[index];
			index++;
			long a = current.A;
			long b = current.B;
			
			long numBuy = Math.Min(rest, b);
			ans += numBuy * a;
			rest -= numBuy;			
		}		
		
		Console.WriteLine(ans);
	}	
}