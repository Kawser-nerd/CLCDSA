using System;
using System.Collections;
using System.Collections.Generic;


public class C
{
	public static void Main()
	{
		int N = Int32.Parse(Console.ReadLine());
		
		int[] A = new int[N];
		string[] args = Console.ReadLine().Split(' ');
		for(int i = 0; i < N; i++)
			A[i] = Int32.Parse(args[i]);
		
		int result = gcd(A[0], A[1]);
		for(int i = 2; i < N; i++)
			result = gcd(result, A[i]);
		
		Console.WriteLine(result);		
	}
	
	public static int gcd(int x, int y)
	{
		return (y == 0) ? x : gcd(y, x % y);
	}	
}