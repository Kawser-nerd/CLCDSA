import java.io.*;
import java.util.*;
import java.text.*;

public class D
{
	public PrintStream out=System.out;
	public PrintStream err=System.err;
	public Scanner in=new Scanner(System.in);
	public DecimalFormat fmt=new DecimalFormat("0.000000");
	
	public int rn,cn;
	public int[][] ID;
	public char[][] g;

	public int n;
	public int[][] GE;
	public boolean[] isT;

	//Down, Up, Right, Left
	public int[] dx={1,-1,0,0};
	public int[] dy={0,0,1,-1};
	

	public void main()
	{
		try
		{
//			err=new PrintStream(new FileOutputStream("error.log"),true);			
				int TCase,cc;
				
				long startTime=System.currentTimeMillis();
				
				int i,j,ii,jj,k,x,y;

				TCase=in.nextInt();
				for(cc=1;cc<=TCase;++cc)
				{
					rn=Int(); cn=Int();
					g=new char[rn][];
					for(i=0;i<rn;++i)
					{
						g[i]=Token().toCharArray();
					}

					//calc ID and n
					ID=new int[rn][cn];
					n=0;
					for(i=0;i<rn;++i)
					for(j=0;j<cn;++j)
					{
						if(g[i][j]!='.')
						{
							ID[i][j]=n; ++n;
						}
						else
						{
							ID[i][j]=-1;
						}
					}

					//calc graph: GE,isT
					isT=new boolean[n];
					GE=new int[n][];
					
					for(i=0;i<rn;++i)
					for(j=0;j<cn;++j)
					if(ID[i][j]>=0)
					{
						x=ID[i][j];

						if(g[i][j]=='T') isT[x]=true;

						ArrayList<Integer> L = new ArrayList<Integer>();

						for(k=0;k<dx.length;++k)
						{
							ii=i+dx[k]; jj=j+dy[k];
							if(valid(ii,jj) && ID[ii][jj]>=0)
							{
								y=ID[ii][jj];
								L.add(y);
							}
						}

						GE[x]=IAL2ia(L);
					}

					int res=solve();

					out.println("Case #"+cc+": "+res);
				}
				
				err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"ms");
		}
		catch(Exception e) { e.printStackTrace(); }
	}
	
	public int score;
	public int[] pre,cost;
	public boolean[] fix;
	public TreeSet<Integer> Sor;

	public TreeSet<DState> T;

	public int solve()
	{
		int i,j,k,x,y;

		score = 0;
		fix=new boolean[n];

		pre=new int[n];
		cost=new int[n];

		Sor=new TreeSet<Integer>();
		Sor.add(ID[0][0]);
		
Dijkstra:
		//run dijkstra on trees
		while(true)
		{
			Arrays.fill(pre,-1);
			Arrays.fill(cost,oo);

			T=new TreeSet<DState>();
			
			for(Integer sor : Sor)
			{
				T.add(new DState(sor,0));
				cost[sor]=0;
			}

			//get SP to a non-fixed tree
			while(!T.isEmpty())
			{
				//get point to relax
				DState cur = T.first();
				T.remove(cur);
				x=cur.x;
				
				//handle if cur is non-fixed tree
				if(isT[x] && !fix[x])
				{
					//fix SP, 
					int z=x;
					while(z>=0)
					{
						if(!fix[z])
						{
							fix[z]=true;
							score+=cost[z];
						}
						z=pre[z];
					}

					//add Sor, 
					Sor.add(x);

					//re-run Dijk
					continue Dijkstra;
				}

				//relax
				for(i=0;i<GE[x].length;++i)
				{
					y=GE[x][i];
					if(cost[x]+1<cost[y])
					{
						if(cost[y]<oo)
						{
							T.remove(new DState(y,cost[y]));
						}

						cost[y]=cost[x]+1;
						pre[y]=x;
						T.add(new DState(y,cost[y]));
					}
				}
			}

			//no new tree, get cost of rest
			for(int z=0;z<n;++z)
			{
				if(!fix[z])
				{
					fix[z]=true;
					score+=cost[z];
				}
			}
			break;
		}

		return score;
	}

	public int oo=987654321;

	//DState for dijkstra
	private class DState implements Comparable<DState>
	{
		public int x, cost;

		public DState(int xx,int cc) { x=xx; cost=cc; }

		public int compareTo(DState u)
		{
			if(cost!=u.cost) return cost-u.cost;
			return x-u.x;
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
	}
	
	public int[] IAL2ia(ArrayList<Integer> v)
	{
		int[] ret=new int[v.size()];
		for(int i=0;i<ret.length;i++) ret[i]=v.get(i);
		return ret;
	}

	public boolean valid(int x,int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		(new D()).main();
	}
}

