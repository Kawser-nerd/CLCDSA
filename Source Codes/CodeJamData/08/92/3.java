import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public int rn,cn;
	public int dx1,dy1,dx2,dy2;
	public boolean[][] set;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
				int TCase,cc;
				int x,y;

				long startTime=System.currentTimeMillis();
				
				TCase=in.nextInt();
				for(cc=1;cc<=TCase;++cc)
				{
					rn=Int(); cn=Int();
					dx1=Int(); dy1=Int();
					dx2=Int(); dy2=Int();
					x=Int(); y=Int();
					
					set=new boolean[rn][cn];
					int res=calc(x,y);

					out.println("Case #"+cc+": "+res);
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}
	
	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public int calc(int x,int y)
	{
		ArrayList<Pair> Q=new ArrayList<Pair>();
		
		set[x][y]=true;
		Q.add(new Pair(x,y));

		int h=0;
		int xx,yy;

		Pair p;
		while(h<Q.size())
		{
			p=Q.get(h); ++h;
			
			xx=p.x+dx1; yy=p.y+dy1;
			
			if(valid(xx,yy) && !set[xx][yy])
			{
				set[xx][yy]=true;
				Q.add(new Pair(xx,yy));
			}

			xx=p.x+dx2; yy=p.y+dy2;
			
			if(valid(xx,yy) && !set[xx][yy])
			{
				set[xx][yy]=true;
				Q.add(new Pair(xx,yy));
			}
		}

		return Q.size();
	}
	
	private class Pair implements Comparable<Pair>
	{
		public int x,y;
		public Pair(int xx,int yy) { x=xx; y=yy; }

		public int compareTo(Pair u)
		{
			if(x!=u.x) return x-u.x;
			return y-u.y;
		}
	}
	

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new B()).main();
	}
}

