
import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	public long[] cost, size;
	public int[] head, pos;
	public long sum, capacity, R;
	public int n;
	
	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			int i;
			
			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				R = in.nextLong();
				capacity = in.nextLong();
				n = in.nextInt();
				
				size = new long[n];
				for(i=0;i<n;++i) 
				{
					size[i] = in.nextLong();
				} 
				
				out.println("Case #" + cc + ": " + go());
				
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public long go()
	{
		int i, k;
		
		sum = 0;
		for(i=0;i<n;++i) sum += size[i];
		
		if(sum <= capacity) return R*sum;
				
		cost = new long[n+10];
		head = new int[n+10];
		pos = new int[n];
		Arrays.fill(pos, -1);
		
		k = 0;
		i = 0;
		
		long res = 0;
		long r = R;
		long load, x;
		int len;
		
		while(r > 0)
		{
			//new head of list
			head[k] = i;
			cost[k] = 0;
			
			if(pos[i] >= 0)
			{
				len = k - pos[i];
				long S = 0;
				for(int j = pos[i]; j < k; ++j) S += cost[j];
				
				x = r/len;
				res += x * S;
				r = r%len;
				
				for(int j=0;j<r;++j) res += cost[pos[i] + j];
				return res;
			}
			else
			{
				pos[i] = k;
				
				load = 0;
				while(load + size[i] <= capacity)
				{
					load += size[i];
					i = (i+1)%n;
				}
				
				cost[k] = load;
				res += load;
				++k;
				--r;
			}
		}
		
		return res;
	}
	
	public int iInt() { return in.nextInt(); }
	public long iLong() { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new C()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}


