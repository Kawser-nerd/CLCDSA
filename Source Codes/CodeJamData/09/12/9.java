import java.io.*;
import java.util.*;
import java.text.*;

public class B
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000");
	
	public int HR, VR, HB, VB, rn, cn;
	public long[][] cost;

	public int[][] S, W, T, P;
	
	public long T18 = 1000000000000000000L;
	public long oo = 4L*T18;

	//Down, Up, Right, Left
	public int[] dx = { 1,-1, 0, 0};
	public int[] dy = { 0, 0, 1,-1};
	public int Down = 0, Up = 1, Right = 2, Left = 3;

	public TreeSet<DState> Q;

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);		

			int TCase,cc;
			int i,j,k,x,y;
			int xx,yy;
			long t;
			int Tx, Ty;

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				HR = Int();
				VR = Int();

				HB = HR+1;
				VB = VR+1;

				rn = 2*HB;
				cn = 2*VB;

				S = new int[HR][VR];
				W = new int[HR][VR];
				T = new int[HR][VR];
				P = new int[HR][VR];

				for(i=0;i<HR;++i)
				for(j=0;j<VR;++j)
				{
					S[i][j] = Int();
					W[i][j] = Int();
					T[i][j] = Int();

					T[i][j] = T[i][j]%(S[i][j]+W[i][j]);
					P[i][j] = S[i][j]+W[i][j];
				}

				cost = new long[rn][cn];
				init(cost, oo);
				Q = new TreeSet<DState>();

				x = rn-2; y = 1;
				cost[x][y] = 0;
				Q.add(new DState(x, y, cost[x][y]));
				
				Tx = 1; Ty = cn-2;
				
				DState now, nxt;
				while(true)
				{
					now = Q.first();
					Q.remove(now);
					
					x = now.x; y = now.y;
					if(x==Tx && y==Ty) break;

					//err.println("("+x+","+y+","+now.cost+")");

					for(k=0;k<dx.length;++k)
					{
						xx = x+dx[k]; yy = y+dy[k];
						if(!valid(xx, yy)) continue;
						
						t = move(x, y, xx, yy, k, now.cost);
						if(cost[xx][yy] > t)
						{
							if(cost[xx][yy] < oo) Q.remove(new DState(xx,yy, cost[xx][yy]));

							cost[xx][yy] = t;
							Q.add(new DState(xx,yy,cost[xx][yy]));
						}
					}
				}

				out.println("Case #"+cc+": "+cost[Tx][Ty]);
			}
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	//moving cost from (x, y) --> (xx,yy)
	public long move(int x, int y, int xx, int yy, int dir, long t)
	{
		int i, j;
		long s, wait;
		if(dir==Down)
		{
			//blocks
			if(x%2==0) return t+2;
			
			//no movement on side
			if(y==0 || y==cn-1) return oo;

			//streets
			i = x/2;
			if(y%2==0)	j = (y-1)/2;
			else j = y/2;
			
			s = (t + S[i][j]+W[i][j] - T[i][j])%(S[i][j]+W[i][j]);

			if(s < S[i][j]) wait = 0;
			else wait = S[i][j]+W[i][j] - s;
			
			return t+wait+1;
		}
		else if(dir==Up)
		{
			//blocks
			if(x%2==1) return t+2;
			
			//no movement on side
			if(y==0 || y==cn-1) return oo;

			//streets
			i = (x-1)/2;
			if(y%2==0)	j = (y-1)/2;
			else j = y/2;
			
			s = (t + S[i][j]+W[i][j] - T[i][j])%(S[i][j]+W[i][j]);

			if(s < S[i][j]) wait = 0;
			else wait = S[i][j]+W[i][j] - s;
			
			return t+wait+1;
		}
		else if(dir==Left)
		{
			//blocks
			if(y%2==1) return t+2;
			
			//no movement on side
			if(x==0 || x==rn-1) return oo;

			//streets
			j = (y-1)/2;
			if(x%2==0) i = (x-1)/2;
			else i = x/2;

			s = (t + S[i][j]+W[i][j] - T[i][j])%(S[i][j]+W[i][j]);

			if(s >= S[i][j]) wait = 0;
			else wait = S[i][j] - s;
			
			return t+wait+1;
		}
		else if(dir==Right)
		{
			//blocks
			if(y%2==0) return t+2;
			
			//no movement on side
			if(x==0 || x==rn-1) return oo;

			//streets
			j = y/2;
			if(x%2==0) i = (x-1)/2;
			else i = x/2;

			s = (t + S[i][j]+W[i][j] - T[i][j])%(S[i][j]+W[i][j]);

			if(s >= S[i][j]) wait = 0;
			else wait = S[i][j] - s;
			
			return t+wait+1;
		}

		throw new RuntimeException("Unknown direction!");
	}

	//DState for dijkstra, where node = (x,y)
	private class DState implements Comparable<DState>
	{
		public int x, y;
		public long cost;

		public DState(int xx, int yy, long cc) { x=xx; y=yy; cost=cc; }

		public int compareTo(DState u)
		{
			if(cost!=u.cost) return cost < u.cost ? -1 : 1;
			if(x!=u.x) return x - u.x;
			return y-u.y;
		}
	}

	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }

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
	}

	public void init(long[][] A, long val)
	{ 
		for(int i=0;i<A.length;++i) Arrays.fill(A[i], val); 
	}

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public int lcm(int a,int b) { return (a/gcd(a,b))*b; }
	public int gcd(int a,int b) 
	{ 
		if(a<0) a=-a; if(b<0) b=-b;
		return b==0?a:gcd(b,a%b);
	}

	public static void main(String[] args)
	{
		long startTime=System.currentTimeMillis();

		(new B()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}

