import java.io.*;
import java.util.*;
import java.text.*;

public class E
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public int rn,cn,lim,mask;
	public char[][] g;

	public int[][][] sol;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
				int TCase,cc;
				
				long startTime=System.currentTimeMillis();
				
				int i,j,k,x,y;

				TCase=in.nextInt();
				for(cc=1;cc<=TCase;++cc)
				{
					rn = Int();
					cn = Int();
					g=new char[rn][];
					for(i=0;i<rn;++i) g[i]=Token().toCharArray();

					lim=(1<<cn);
					mask = lim-1;
					sol=new int[rn][cn][lim];
					init(sol,-1);

					err.println("Case #"+cc+": "+solve(0,0,0));
					out.println("Case #"+cc+": "+solve(0,0,0));
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public boolean in(int x,int set) { return ((1<<x)&set)!=0; }
	//Turn on bit x
	public int on(int x,int set) { return (set | (1<<x)); }
	//Turn off bit x
	public int off(int x,int set) { return (set ^ (set & (1<<x)) );}


	public int solve(int i,int j,int set)
	{
		if(i>=rn)
		{
			return 0;
		}
		if(sol[i][j][set]>=0) return sol[i][j][set];

		int ret=0;
		
		int A,B;
		//check cell value, make decision
		if(g[i][j]=='#') //blue
		{
			A = blue(i,j,set);
			B = 0;
		}
		else if(g[i][j]=='.') //white
		{
			A = 0;
			B = white(i,j,set);
		}
		else //g[i][j]=='?'
		{
			A = blue(i,j,set);
			B = white(i,j,set);
		}

		ret=Math.max(A,B);

		return sol[i][j][set]=ret;
	}

	public int blue(int i,int j,int set)
	{
		//get next i,j
		int ni,nj,nset;
		ni=i; nj = j+1;

		if(nj>=cn)
		{
			++ni; nj=0;
		}
		
		nset = ((set<<1)+1)&mask;

		int local = 4;
		if(isBlueCB(i,j,set)) local -= 2;
		if(isBlueRB(i,j,set)) local -= 2;

		return local + solve(ni, nj, nset);
	}

	public int white(int i,int j,int set)
	{
		//get next i,j
		int ni,nj,nset;
		ni=i; nj = j+1;

		if(nj>=cn)
		{
			++ni; nj=0;
		}
		
		nset = ((set<<1)+0)&mask;

		return solve(ni,nj,nset);
	}

	public boolean isBlueCB(int i,int j,int set)
	{
		if(!valid(i,j-1)) return false;
		return in(0,set);
	}

	public boolean isBlueRB(int i,int j,int set)
	{
		if(!valid(i-1,j)) return false;
		return in(cn-1,set);
	}

	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }


	public void init(int[][][] A,int val)
	{
		for(int i=0;i<A.length;++i)
		for(int j=0;j<A[i].length;++j) Arrays.fill(A[i][j],val);
	}	

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new E()).main();
	}
}

