package Andra;

import java.util.*;

public class CumulativeTable 
{
	public static final long MOD = 1000000007;
	private long [] sum;
	private int [] degreeTwo;
	private int n;
	
	public CumulativeTable(int n)
	{
		this.n = n;
		this.sum = new long [n + 1];
		this.degreeTwo = new int [n + 1];
		calculateDegrees();
	}
	
	private void calculateDegrees()
	{
		degreeTwo [0] = 1;
		degreeTwo [1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if ((i & 1) == 0)
				degreeTwo [i] = degreeTwo [i >> 1] * 2;
			else
				degreeTwo [i] = 1;
		}
	}
	
	public void reset()
	{
		for (int i = 0; i < n; i++)
			sum [i] = 0;
	}
	
	public void add (int index, long value)
	{
		int i = index;
		while (i <= n)
		{
			sum [i] = (sum [i] + value) % MOD;
			i = i + degreeTwo [i];
		}
	}

	public long count (int index)
	{
		int i = index;
		long toReturn = 0;
		while (i >= 0)
		{
			toReturn = (toReturn + sum [i]) % MOD;
			i = i - degreeTwo [i];
		}
		return toReturn;
	}

	public static void main(String[] args) 
	{
		Random rnd = new Random ();
		int n = 100;
		int [] a = new int [n];
		CumulativeTable ct = new CumulativeTable(n);
		for (int i = 0; i < n; i++)
			a [i] = 0;
		for (int i = 0; i < 10; i++)
		{
			int index = rnd.nextInt(n);
			int value = rnd.nextInt(1000);
			a [index] = a [index] + value;
			ct.add(index, value);
			int sum = 0;
			for (int j = 0; j <= index; j++)
				sum += a [j];
			System.out.println(sum);
			System.out.println(ct.count(index));
		}
	}
	
}
