import java.io.*;
import java.util.*;

import java.util.*;

public class B
{
	public static HashSet<Integer> primes (int x, int min)
	{
		HashSet<Integer> out = new HashSet<Integer>();
		if (x < min)
			return out;
		if (x % 2 == 0)
		{
			if (min <= 2)
				out.add(2);
			while (x % 2 == 0)
				x /= 2;
		}
		
		for (int i = 3; i*i <= x; i += 2)
		{
			if (x % i == 0)
			{
				if (min <= i)
					out.add(i);
				while (x % i == 0)
					x /= i;
			}
		}
		if (x >= min)
			out.add(x);
		return out;
	}
	
	public static void main (String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("B-small.out"));
		
		int num = Integer.parseInt(br.readLine());
		for (int z = 1; z <= num; z++)
		{
			String[] sp = br.readLine().split(" ");
			int low = Integer.parseInt(sp[0]);
			int high = Integer.parseInt(sp[1]);
			int prime = Integer.parseInt(sp[2]);
			HashSet<Integer>[] x = new HashSet [high-low+1];
			for (int i = 0; i < x.length; i++)
				x[i] = primes(i+low, prime);
			
			int out = x.length;
			boolean done = false;
			while (!done)
			{
				done = true;
				for (int i = 0; i < x.length; i++)
				{
					if (x[i] == null)
						continue;
					for (int j = i+1; j < x.length; j++)
					{
						if (x[j] == null)
							continue;
						
						boolean join = false;
						if (x[i].size() < x[j].size())
						{
							for (int p : x[i])
								if (x[j].contains(p))
								{
									join = true;
									break;
								}
						}
						else
						{
							for (int p : x[j])
								if (x[i].contains(p))
								{
									join = true;
									break;
								}
						}
						
						if (join)
						{
							x[i].addAll(x[j]);
							x[j] = null;
							done = false;
							out--;
						}
					}
				}
			}
			
			ps.println("Case #" + z + ": " + out);
		}
		
		br.close();
		ps.close();
	}
}