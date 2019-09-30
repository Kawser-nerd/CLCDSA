import java.io.*;
import java.util.*;
import java.text.*;

public class D
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public final int dunno=-1,Alice=0,Bob=1;
	public int[][][] sol;

	public int rn,cn,n,lim;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
				int TCase,cc;
				
				long startTime=System.currentTimeMillis();
				
				TCase=in.nextInt();
				for(cc=1;cc<=TCase;++cc)
				{
					rn=Int();
					cn=Int();
					boolean[][] B=new boolean[rn][cn];

					int i,j,k;
					int kx,ky;
					kx=ky=-1;
					for(i=0;i<rn;++i)
					{
						char[] L = Token().toCharArray();
						for(j=0;j<cn;++j)
						{
							if(L[j]=='.') B[i][j]=true;
							else if(L[j]=='#') B[i][j]=false;
							else
							{
								//L[j]=='K';
								B[i][j]=false;
								kx = i;
								ky = j;
							}
						}
					}
					
					n=rn*cn;
					lim=(1<<n);
					sol=new int[lim][rn][cn];
					init(sol,dunno);

					out.println("Case #"+cc+": "+(solve(encode(B),kx,ky,Alice)==Alice?"A":"B"));
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}

	public void init(int[][][] A,int val)
	{
		for(int i=0;i<A.length;++i)
		for(int j=0;j<A[i].length;++j) Arrays.fill(A[i][j],val);
	}

	//8 Directions
	public int[] dx={1,1,1,0,0,-1,-1,-1};
	public int[] dy={-1,0,1,-1,1,-1,0,1};

	public int solve(int set,int r,int c,int who)
	{
		if(sol[set][r][c]!=dunno) return sol[set][r][c];
		int ret;
		boolean[][] B=decode(set);

		int i,j,k,x,y;
		int Ac,Bc,sub;

		Ac=Bc=0;
		for(k=0;k<dx.length;++k)
		{
			x=r+dx[k]; y=c+dy[k];
			if(valid(x,y) && B[x][y])
			{
				B[x][y]=false;
				sub=solve(encode(B),x,y,1-who);

				if(sub==Alice) ++Ac;
				else ++Bc;

				B[x][y]=true;
			}
		}

		if(who==Alice)
		{
			if(Ac>0) return sol[set][r][c]=Alice;
			return sol[set][r][c]=Bob;
		}
		else
		{
			//who==Bob
			if(Bc>0) return sol[set][r][c]=Bob;
			return sol[set][r][c]=Alice;
		}
	}

	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public boolean[][] decode(int set)
	{
		int t,r,c;
		boolean[][] R=new boolean[rn][cn];

		t=0;
		for(r=0;r<rn;++r)
		for(c=0;c<cn;++c)
		{
			R[r][c]=in(t,set);
			++t;
		}

		return R;
	}

	public int encode(boolean[][] B)
	{
		int ret,i,j,t;
		ret=0;
		for(i=rn-1;i>=0;--i)
		for(j=cn-1;j>=0;--j)
		{
			ret=(ret<<1)+(B[i][j]?1:0);
		}
		return ret;
	}
	
	public boolean in(int x,int set) { return ((1<<x)&set)!=0; }

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new D()).main();
	}
}
