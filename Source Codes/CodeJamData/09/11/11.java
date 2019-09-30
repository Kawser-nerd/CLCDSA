import java.util.*;
import static java.lang.Math.*;

public class A 
{
	void p(String s)
	{
		System.out.println(s);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int i = 1; i <= T;i++)
		{
			String[] s = sc.nextLine().split(" ");
			int[] bases = new int[s.length];
			for(int j = 0; j < bases.length;j++)
				bases[j] = Integer.parseInt(s[j]);
			
			for(long j = 2;;j++)
			{
				boolean good = true;
				for(int b: bases)
				{
					int[] n = new int[10];
					long temp = j;
					while(temp != 0)
					{
						n[(int)(temp%b)]++;
						temp/=b;
					}
					//System.out.println(j+" "+Arrays.toString(n)+" "+b);
					if(!isHappy(new Case(n,b)))
					{
						good = false;
						break;
					}
				}
				if(good)
				{
					System.out.println("Case #"+i+": "+j);
					break;
				}
			}
			System.err.println(i);
			
		}

	}
	static HashMap<Case,Boolean> isHappy = new HashMap<Case,Boolean>();
	public static boolean isHappy(Case c)
	{
		//System.out.println(Arrays.toString(c.numD)+" "+c.base);
		if(c.numD[0] == 1)
		{
			boolean done = true;
			for(int i = 1; i < 10;i++)
			{
				if(c.numD[i] != 0)
				{
					done = false;
					break;
				}
			}
			if(done)
				return false;
		}
		if(c.numD[0] == 0 && c.numD[1] == 1)
		{
			boolean done = true;
			for(int i = 2; i < 10;i++)
			{
				if(c.numD[i] != 0)
				{
					done = false;
					break;
				}
			}
			if(done)
				return true;
		}
		if(isHappy.containsKey(c))
		{
			return isHappy.get(c);
		}		
		isHappy.put(c,false);
		int nn = 0;
		for(int i = 0; i < 10;i++)
		{
			nn += (i)*(i)*c.numD[i];
		}
		int[] next = new int[10];
		while(nn != 0)
		{
			next[nn%c.base]++;
			nn /= c.base;
		}
		boolean ans = isHappy(new Case(next,c.base));
		isHappy.put(c,ans);
		return ans;
	}
	private static class Case 
	{
		int[] numD;
		int base;
		Case(int[] n, int b)
		{
			numD = n;
			base = b;
		}
		public int hashCode()
		{
			int ans = 0;
			for(int i = 0; i < 10;i++)
			{
				ans ^= numD[i] << (3*i);
			}
			ans ^= base;
			return ans;
		}
		public boolean equals(Object o)
		{
			Case c = (Case) o;
			for(int i = 0; i < 10;i++)
				if(numD[i] != c.numD[i])
					return false;
			if(base != c.base)
				return false;
			return true;
		}
	}
}
