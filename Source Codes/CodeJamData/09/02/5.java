import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000");
	
	public int rn, cn;
	public int[][] H;
	public char[][] res;
	public Pair[][] nxt;

	public int[] dx = {-1,0,0,1};
	public int[] dy = {0,-1,1,0};

	//int pair
	private class Pair implements Comparable<Pair>
	{
		public int x,y;
		public Pair(int xx,int yy) { x=xx; y=yy; }

		public int compareTo(Pair u)
		{
			if(x!=u.x) return x-u.x;
			return y-u.y;
		}

		public String toString()
		{
			return "("+x+", "+y+")";
		}
	}

	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"),true);			
			int TCase,cc;
			int i,j,k,x,y,xx,yy;
			int lowest;

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				rn = Int(); cn = Int();

				H = new int[rn][cn];
				nxt = new Pair[rn][cn];

				res = new char[rn][cn];
				init(res, '?');

				for(i=0;i<rn;++i)
				for(j=0;j<cn;++j) H[i][j] = Int();

				for(x=0;x<rn;++x)
				for(y=0;y<cn;++y)
				{
					lowest = H[x][y];
					for(k=0;k<4;++k)
					{
						xx = x+dx[k]; yy=y+dy[k];
						if(valid(xx,yy) && H[xx][yy] < lowest)
						{
							nxt[x][y] = new Pair(xx,yy);
							lowest = H[xx][yy];
						}
					}
					//err.println("nxt["+x+"]["+y+"] = "+nxt[x][y]);
				}
				
				char lab = 'a';
				for(i=0;i<rn;++i)
				for(j=0;j<cn;++j)
				if(res[i][j] == '?')
				{
					up(i, j, lab);
					++lab;
				}

				out.println("Case #"+cc+":");
				for(i=0;i<rn;++i)
				{
					for(j=0;j<cn;++j) out.print(res[i][j]+" ");
					out.println();
				}
				err.println("Done Case "+cc);
			}
			
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public void up(int i, int j, char lab)
	{
		Pair p = new Pair(i, j);
		int x, y, k,a, b;

		while(nxt[p.x][p.y]!=null) p = nxt[p.x][p.y];
		down(p, lab);
	}
	
	//Use BFS
	public void down(Pair p, char lab)
	{
		Pair T;
		Queue<Pair> Q = new LinkedList<Pair>();
		Q.offer(p);
		
		res[p.x][p.y] = lab;

		int k, x, y;
		while(!Q.isEmpty())
		{
			p = Q.poll();
			//err.println("p = "+p);
			for(k=0;k<4;++k)
			{
				T = new Pair(p.x+dx[k], p.y+dy[k]);
				//err.println("T = "+T);

				if(valid(T.x, T.y) && nxt[T.x][T.y]!=null && p.compareTo(nxt[T.x][T.y])==0)
				{
					res[T.x][T.y] = lab;
					//err.println("res["+T.x+"]["+T.y+"] = "+lab);
					Q.offer(T);
				}
			}
		}
	}
	
	public void init(char[][] A, char val) 
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	}

	public boolean valid(int x, int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime=System.currentTimeMillis();

		(new B()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}
