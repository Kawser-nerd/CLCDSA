import java.io.*;
import java.util.*;
import java.text.*;

public class AS
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000000");
	
	private class DState implements Comparable<DState>
	{
		public Pair[] p;

		public DState(ArrayList<Pair> A)
		{
			p = A.toArray(new Pair[0]);
			Arrays.sort(p);
		}

		public DState(Pair[] pp)
		{
			p = pp.clone();
			Arrays.sort(p);
		}

		public int compareTo(DState u)
		{
			int i, c;
			for(i=0;i<p.length;++i)
			{
				c = p[i].compareTo(u.p[i]);
				if(c != 0) return c;
			}

			return 0;
		}
	}

	private class QState implements Comparable<QState>
	{
		public DState now;
		public int cost;

		public QState(DState dd, int cc)
		{
			now = dd;
			cost = cc;
		}

		public int compareTo(QState u)
		{
			if(cost != u.cost) return cost - u.cost;
			return now.compareTo(u.now);
		}
	}

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

		public boolean equals(int tx, int ty) { return x==tx && y==ty; }

		public Pair clone() { return new Pair(x, y); }
		public String toString() { return "("+x+","+y+")"; }
	}

	public TreeMap<DState, Integer> cost;
	public TreeSet<QState> Q;

	public DState goal, sor;
	public int rn, cn;
	public boolean[][] G;

	//Down, Up, Right, Left
	public int[] dx = { 1,-1, 0, 0};
	public int[] dy = { 0, 0, 1,-1};

	public void main()
	{
		try
		{
			//err = new PrintStream(new FileOutputStream("error.log"), true);			
			int TCase,cc;
			int i, j, k, x, y;

			TCase = in.nextInt();
			for(cc=1;cc<=TCase;++cc)
			{
				rn = in.nextInt();
				cn = in.nextInt();

				ArrayList<Pair> GA, SA;
				SA = new ArrayList<Pair>();
				GA = new ArrayList<Pair>();
				
				G = new boolean[rn][cn];

				for(i=0;i<rn;++i)
				{
					char[] g = in.next().toCharArray();
					for(j=0;j<cn;++j)
					{
						G[i][j] = (g[j] != '#');
						if(g[j]=='o')
						{
							SA.add(new Pair(i, j));
						}
						else if(g[j]=='x')
						{
							GA.add(new Pair(i, j));
						}
						else if(g[j]=='w')
						{
							SA.add(new Pair(i, j));
							GA.add(new Pair(i, j));
						}
					}
				}
				
				sor = new DState(SA);
				goal = new DState(GA);

				Q = new TreeSet<QState>();
				cost = new TreeMap<DState, Integer>();

				cost.put(sor, 0);
				Q.add(new QState(sor,0));
				
				QState X;
				while(!Q.isEmpty())
				{
					X = Q.first();
					Q.remove(X);

					if(X.now.equals(goal)) break;
					
					boolean S1 = safe(X.now.p);
					boolean S2;

					Pair[] nxt = X.now.p.clone();
					
					for(i=0;i<nxt.length;++i)
					{
						for(k=0;k<dx.length;++k)
						{
							Pair T = new Pair(nxt[i].x+dx[k], nxt[i].y+dy[k]);
							if(empty(T.x, T.y, X.now.p) && empty(nxt[i].x-dx[k], nxt[i].y-dy[k], X.now.p))
							{
								nxt[i] = T;
								DState d = new DState(nxt);

								if(S1 || safe(d.p))
								if(!cost.containsKey(d) || cost.get(d) > X.cost+1)
								{
									if(cost.containsKey(d)) Q.remove(new QState(d, cost.get(d)));

									cost.put(d, X.cost+1);
									Q.add(new QState(d, cost.get(d)));

						/*			err.println("from");
									print(X.now.p);
									err.println("to");
									print(d.p);
									err.println("=============================================");
									*/
								}
							}

							nxt[i] = X.now.p[i];
						}
					}
				}

				out.println("Case #"+cc+": " + (cost.containsKey(goal) ? cost.get(goal) : -1));
				err.println("Case #"+cc+": " + (cost.containsKey(goal) ? cost.get(goal) : -1));
			}//end for cc = 1 ... TCase
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()

	public void print(Pair[] p)
	{
		TreeSet<Pair> P = new TreeSet<Pair>();
		for(Pair pp : p) P.add(pp);

		int i, j;
		for(i=0;i<rn;++i)
		{
			for(j=0;j<cn;++j)
			{
				if(P.contains(new Pair(i, j))) err.print("o");
				else err.print(G[i][j]?'.':'#');
			}
			err.println();
		}
	}

	public boolean empty(int x,int y, Pair[] block) 
	{ 
		if(!(0<=x && x<rn && 0<=y && y<cn)) return false;
		for(int i=0;i<block.length;++i) if(block[i].equals(x, y)) return false;
		return G[x][y]; 
	}
	
	public boolean safe(Pair[] p)
	{
		TreeSet<Pair> P = new TreeSet<Pair>();
		for(Pair pp : p) P.add(pp);

		Queue<Pair> Q = new LinkedList<Pair>();
		TreeSet<Pair> seen = new TreeSet<Pair>();

		Q.offer(p[0]);
		seen.add(p[0]);
		
		int x,y,k;
		Pair now, nxt;
		while(!Q.isEmpty())
		{
			now = Q.poll();
			for(k=0;k<dx.length;++k)
			{
				nxt = new Pair(now.x+dx[k], now.y+dy[k]);
				if(seen.contains(nxt)) continue;

				if(P.contains(nxt))
				{
					seen.add(nxt);
					Q.offer(nxt);
				}
			}
		}

		return seen.size() == P.size();
	}

	public int iInt() { return in.nextInt(); }
	public long iLong() { return in.nextLong(); }
	public String iToken() { return in.next(); }
	public String iLine() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new AS()).main();
		long endTime = System.currentTimeMillis();
		
		long ms = endTime - startTime;
		long sec = ms/1000; ms = ms%1000;
		long min = sec/60; sec = sec%60;

		System.err.println("Time Spent: " + min + " minute(s) " + sec + " second(s) " + ms + " (ms)");
	}
}
