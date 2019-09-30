import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public int rn,cn,midr,n;
	public int[][] d;
	
	public int[][] adj;

	public int lim;

	//9 Directions
	public int[] dx={0,1,1,1,0,0,-1,-1,-1};
	public int[] dy={0,-1,0,1,-1,1,-1,0,1};

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
					rn = Int(); cn =Int();
					midr = rn/2;

					d=new int[rn][cn];
					
					for(i=0;i<rn;++i)
					for(j=0;j<cn;++j)
					{
						d[i][j]=Int();
					}

					int res=0;
					
					n=rn*cn;
					
					makeAdj();
				
					lim=(1<<(rn*cn));
					int set;

					for(set=0;set<lim;++set)
					{
						int value = calc(set);
						if(value>res)
						{
							if(sat(set)) res = value;
						}
					}
					
					err.println("Case #"+cc+": "+res);
					out.println("Case #"+cc+": "+res);
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public void makeAdj()
	{
		adj=new int[n][];
		ArrayList<Integer> L;

		int i,j,ii,jj,k,x,y;

		for(i=0;i<rn;++i)
		for(j=0;j<cn;++j)
		{
			x=(i*cn)+j;
			L=new ArrayList<Integer>();

			for(k=0;k<9;++k)
			{
				ii=i+dx[k]; jj=j+dy[k];
				if(valid(ii,jj))
				{
					y=(ii*cn)+jj;
					L.add(y);
				}
			}

			adj[x]=IAL2ia(L);
		}
	}

	public int[] IAL2ia(ArrayList<Integer> v)
	{
		int[] ret=new int[v.size()];
		for(int i=0;i<ret.length;i++) ret[i]=v.get(i);
		return ret;
	}

	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public int calc(int set)
	{
		int c,r;
		int ret=0;
		r=midr;
		for(c=0;c<cn;++c)
		{
			ret+=count(r,c,set);
		}
		return ret;
	}

	public int count(int r,int c,int set) { return (((1<<(r*cn+c))&set)!=0)?1:0; }
	
	public int count(int x,int set)
	{
		return (((1<<x)&set)!=0)?1:0;
	}

	public boolean sat(int set)
	{
		int x,cnt;
		int j,y;

		for(x=0;x<n;++x)
		{
			cnt=0;
			for(j=0;j<adj[x].length;++j)
			{
				cnt+=count(adj[x][j],set);
			}
			if(cnt!=d[x/cn][x%cn]) return false;
		}
		
		return true;
	}
	
	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new C()).main();
	}
}

