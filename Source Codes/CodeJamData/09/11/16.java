import java.io.File;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class A
{

	public static void main(String[] args) throws Exception
	{
		new A();
	}
	
	final int oo = (int)1e9;
	
//	TreeMap<state,Boolean> memo = new TreeMap<state,Boolean>();
	
	A() throws Exception
	{		
		Scanner fin = new Scanner(new File("Abf.out"));
		TreeMap<Integer,Integer> cache = new TreeMap<Integer,Integer>();
		while (fin.hasNext())
			cache.put(fin.nextInt(), fin.nextInt());
		Scanner in = new Scanner(System.in);
		for (int T=in.nextInt(),ds=1; T-->0; ++ds)
//		for (int mask=1; mask<(1<<9); ++mask)
		{
//			int emask = mask<<2;
			if (ds==1) in.nextLine();
			Scanner sc = new Scanner(in.nextLine());
			int mask = 0;
			while (sc.hasNextInt())
				mask |= (1<<sc.nextInt());
			System.out.printf("Case #%d: %d%n", ds,cache.get(mask));
//			System.out.printf("%d %d%n", emask,solve(emask));
		}
		
		
	}
	
	int solve(int mask)
	{
		for (int n=2; ; ++n)
			if (happy(n,mask))
				return n;
	}
	
	boolean happy(int n, int mask)
	{
		if (mask == 0)
			return true;
		state s = new state(n,mask);
//		if (memo.containsKey(s))
//			return memo.get(s);
		int base=2;
		while (!on(mask,base))
			++base;
		
		boolean ret;
		if (isHappy(n,base))
			ret = happy(n,mask-(1<<base));
		else
			ret = false;
//		memo.put(s, ret);
		return ret;
	}
	
	boolean isHappy(int n, int base)
	{
		TreeSet<String> S = new TreeSet<String>();
		String s = decToBase(n,base);
		while (!S.contains(s))
		{
			S.add(s);
			s = go(s,base);
			if (s.equals("1"))
				return true;
		}
		return false;
	}
	
	String go(String n, int base)
	{
		long res = 0;
		for (int i=0; i<n.length(); ++i)
		{
			long d = n.charAt(i)-'0';
			res += d*d;
		}
		return decToBase(res,base);
	}
	
	boolean on(int mask, int loc)
	{
		return (mask&(1<<loc))>0;
	}

	final String baseReps = "0123456789ABCDEF";
	final int[] baseVals = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	String decToBase(long d, int b)
	{ // b != +/-1
		StringBuilder base = new StringBuilder();
		while (d != 0)
		{
			int r = (int) (d % b);
			if (r < 0)
				r += Math.abs(b);
			base.insert(0, findBaseRep(r));
			d = (d - r) / b;
		}
		if (base.length() == 0)
			base.append("0");
		return base.toString();
	}

	long baseToDec(String num, int b)
	{
		long dec = 0;
		for (int i = num.length() - 1; i >= 0; i--)
			dec += Math.pow(b, num.length() - i - 1) * findBaseVal(num.charAt(i));
		return dec;
	}

	char findBaseRep(int val)
	{
		for (int i = 0; i < baseVals.length; i++)
			if (baseVals[i] == val)
				return baseReps.charAt(i);
		return ' '; // shouldn't ever happen..
	}

	int findBaseVal(char rep)
	{
		return baseReps.indexOf(rep);
	}
}

class state implements Comparable<state>
{
	int n,mask;
	state(int n, int mask)
	{
		this.n = n;
		this.mask = mask;
	}
	
	public int compareTo(state o)
	{
		int z=n-o.n;
		if (z==0) z=mask-o.mask;
		return z;
	}
}
