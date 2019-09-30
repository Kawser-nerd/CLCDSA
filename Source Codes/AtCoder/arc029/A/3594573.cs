using System;
using System.Collections;
using System.Linq;


public class Test
{	
	public static int min = 999999999;
	public static int A = 0;
	public static int B = 0;
	public static int n =0;
	public static int[] niku= new int[4];

	public static void Main()
	{
		n = int.Parse(Console.ReadLine());

		for(int i = 0 ; i < n ; i++)
		{
			niku[i] = int.Parse(Console.ReadLine());
		}
		string s = "";
		tansaku(s);
		Console.WriteLine(Math.Max(A,B));
	}

	public static void tansaku(string s)
	{
		if(s.Length == n)
		{
			keisan(s);
		}
		else
		{
			tansaku(s+"1");
			tansaku(s+"0");
		}
	}

	public static void keisan(string s)
	{
		char[] c = s.ToCharArray();
		int a = 0;
		int b = 0;
		for(int i = 0 ; i < n ; i++ )
		{
			if(c[i] == '1')
			{
				a += niku[i];
			}
		}

		for(int i = 0 ; i < n ; i++ )
		{
			if(c[i] == '0')
			{
				b += niku[i];
			}
		}

		if(min > Math.Abs(a-b))
		{
			min = Math.Abs(a-b);
			A = a;
			B = b;
		}
	}
}