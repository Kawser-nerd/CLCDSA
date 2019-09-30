import java.io.*;
import java.util.*;
import java.text.*;

public class BSmall
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000");
	
	public int rn, cn, fall;
	public int lim;
	public char[][] g;

	public int[][][][] sol;

	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"),true);			
			int TCase,cc;
			int i, j;
			
			TCase = in.nextInt();
			//out.println(TCase);
			for(cc=1;cc<=TCase;++cc)
			{
				rn = iInt(); cn = iInt();
				fall = iInt();

				g = new char[rn][];
				for(i=0;i<rn;++i) g[i] = in.next().toCharArray();
				
				lim = (1<<cn);
				sol = new int[rn][cn][lim][lim];
				init(sol, -1);
				
				int res = solve(0, 0, raw(g[0]), raw(g[1]));

				/*
				out.println(rn+" "+cn+" "+fall);
				for(i=0;i<rn;++i)
				{
					out.println(new String(g[i]));
				}
				*/
				out.println("Case #"+cc+": "+(res < oo ? ("Yes " + res) : "No"));
			}
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int oo = 987654321;

	public int solve(int i, int j, int cur, int nxt)
	{
		if(sol[i][j][cur][nxt] >= 0) return sol[i][j][cur][nxt];
		
		int ret;
		//last row
		if(i == rn-1)
		{
			ret = 0;

		}
		else
		{
			int k;
			ret = oo;
			//drop left
			for(k=j-1;k>=0;--k)
			{
				//cannot walk here
				if(!in(k, cur)) break;
				//cannot drop down
				if(!in(k, nxt)) continue;

				//can drop at column k
				Result R = drop(i, k, cur, nxt);
				
				if(R != null)
				{
					ret = Math.min(ret, solve(R.i, R.j, R.cur, R.nxt));
				}
				break;
			}

			//drop right
			for(k=j+1;k<cn;++k)
			{
				if(!in(k, cur)) break;
				if(!in(k, nxt)) continue;

				//can drop at column k
				Result R = drop(i, k, cur, nxt);
				
				if(R != null)
				{
					ret = Math.min(ret, solve(R.i, R.j, R.cur, R.nxt));
				}
				break;
			}
			
			//dig
			int Lo, Hi;
			Lo = Hi = j;
			while(Lo-1 >= 0 && in(Lo-1,cur) && !in(Lo-1,nxt)) --Lo;
			while(Hi+1 < cn && in(Hi+1, cur) && !in(Hi+1, nxt)) ++Hi;

			for(k=Lo;k<=Hi;++k)
			{	
				if(k-1 >= 0 && in(k-1, cur) && !in(k-1, nxt))
				{
					ret = Math.min(ret, 1 + solve(i, k, cur, on(k-1, nxt)));
				}

				if(k+1 < cn && in(k+1, cur) && !in(k+1, nxt))
				{
					ret = Math.min(ret, 1 + solve(i, k, cur, on(k+1, nxt)));
				}
			}
		}

		return sol[i][j][cur][nxt] = ret;
	}

	public int raw(char[] v)
	{
		int set = 0;
		for(int i=0;i<cn;++i)
		if(v[i] == '.') set = on(i, set);
		return set;
	}

	public boolean clearPath(int a, int b, int set)
	{
		while(a <= b)
		{
			if(!in(a, set)) return false;
			++a;
		}
		return true;
	}

	private class Result
	{
		public int i,j,cur,nxt;
	}

	public Result drop(int i, int j, int cur, int nxt)
	{
		//(i,j), (i+1, j) are empty
		int k, x, y;
		x = i+1;
		while(x+1 < rn && g[x+1][j]=='.') ++x;
		
		//drop dead
		if(x - i > fall) return null;

		//on (x, j)
		Result R = new Result();
		R.i = x;
		R.j = j;
		R.cur = (x == i+1? nxt : raw(g[x]));
		//x+1 must be raw
		R.nxt = (x+1 < rn ? raw(g[x+1]) : 0);

		return R;
	}

	public boolean in(int x, int set) { return ((1<<x)&set)!=0; }
	//Turn on bit x
	public int on(int x, int set) { return (set | (1<<x)); }
	//Turn off bit x
	public int off(int x, int set) { return (set ^ (set & (1<<x)) ); }


	public void init(int[][][][] A, int val)
	{
		for(int i=0;i<A.length;++i)
		for(int j=0;j<A[i].length;++j)
		for(int k=0;k<A[i][j].length;++k) Arrays.fill(A[i][j][k], val);
	}

	public int iInt() { return in.nextInt(); }
	public long iLong() { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new BSmall()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}
