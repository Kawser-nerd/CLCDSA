import java.util.*;

public class Portal
{
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int N = sc.nextInt();
		for(int i=1;i<=N;i++)
		{
			R = sc.nextInt(); C = sc.nextInt();
			ch = new char[R][];
			for(int j=0;j<R;j++)
				ch[j] = sc.next().toCharArray();
			
			System.out.println("Case #"+i+": "+solve());
		}
	}
	static final int BLUE = 0, YELLOW = 1, INF = 10000000;
	static final int[] dr = new int[] {1,-1,0,0};
	static final int[] dc = new int[] {0,0,1,-1};
	static char[][] ch;
	static int R, C;
	static int[][][][] dist;
	static int[][][][] nearest;
	static int startR, startC, cakeR, cakeC, res;
	
	private static String solve()
	{
		costs.clear();
		res = INF;
		dist = new int[R][C][][];
		nearest = new int[R][C][][];
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				dist[i][j] = getDistance(i, j);
				nearest[i][j] = getNearest(i, j);
			}
		}
		
		State start = new State(startR, startC, 0, 0, 2);
		add(start, 0);
		while(q.size()>0)
		{
			State s = q.remove();
			added.remove(s);
			int cost = costs.get(s);
			for(int i=0;i<4;i++)
			{
				State ns = new State(s.r+dr[i],s.c+dc[i],s.pr,s.pc,s.color);
				add(ns, cost+1);
				if(s.color==2)
				{
					ns = new State(s.r,s.c,
						nearest[s.r][s.c][i][0],nearest[s.r][s.c][i][1],BLUE);
					add(ns, cost);
					ns = new State(s.r,s.c,
						nearest[s.r][s.c][i][0],nearest[s.r][s.c][i][1],YELLOW);
					add(ns, cost);
				}
				else
				{
					int nr = s.color==BLUE?nearest[s.r][s.c][i][0]:s.pr;
					int nc = s.color==BLUE?nearest[s.r][s.c][i][1]:s.pc;
					int or = s.color==YELLOW?nearest[s.r][s.c][i][0]:s.pr;
					int oc = s.color==YELLOW?nearest[s.r][s.c][i][1]:s.pc;
					ns = new State(nr, nc, 0, 0, 2);
					add(ns, cost+dist[s.r][s.c][or][oc]+1);
				}
			}
		}
		
		return res==INF?"THE CAKE IS A LIE":""+res;
	}
	private static int[][] getDistance(int r, int c)
	{
		if(ch[r][c]=='O')
		{
			startR = r; startC = c;
		}
		else if(ch[r][c]=='X')
		{
			cakeR = r; cakeC = c;
		}
		
		int[][] temp = new int[R][C];
		for(int i=0;i<R;i++)
			Arrays.fill(temp[i], INF);
		
		addDist(r, c, 0, temp);
		while(qDist.size()>0)
		{
			r = qDist.remove();
			c = qDist.remove();
			for(int i=0;i<4;i++)
			{
				addDist(r+dr[i], c+dc[i], temp[r][c]+1, temp);
			}
		}
		return temp;
	}
	static Queue<Integer> qDist = new LinkedList<Integer>();
	private static void addDist(int r, int c, int cost, int[][] temp)
	{
		if(r<0 || r>=R || c<0 || c>=C || ch[r][c]=='#' || temp[r][c]<cost)
			return;
		qDist.add(r); qDist.add(c);
		temp[r][c] = cost;
	}
	
	private static int[][] getNearest(int r, int c)
	{
		int[][] ret = new int[4][2];
		for(int i=0;i<4;i++)
		{
			int nr = r, nc = c;
			while(nr>=0 && nr<R && nc>=0 && nc<C && ch[nr][nc]!='#')
			{
				nr += dr[i];
				nc += dc[i];
			}
			nr -= dr[i];
			nc -= dc[i];
			ret[i][0] = nr;
			ret[i][1] = nc;
		}
		return ret;
	}
	
	static Map<State, Integer> costs = new HashMap<State, Integer>();
	static Set<State> added = new HashSet<State>();
	static Queue<State> q = new LinkedList<State>();
	
	private static void add(State state, int cost)
	{
		if(state.r<0 || state.r>=R || state.c<0 || state.c>=C ||
			ch[state.r][state.c]=='#')
			return;
			
		if(state.r==cakeR && state.c==cakeC)
			res = Math.min(res, cost);
		if(!costs.containsKey(state) || costs.get(state)>cost)
		{
			costs.put(state, cost);
			if(!added.contains(state))
			{
				added.add(state);
				q.add(state);
			}
		}
	}
	
	static class State
	{
		final int r, c, pr, pc, color;
		public State(int r, int c, int pr, int pc, int color)
		{
			this.r = r; this.c = c; this.pr = pr; this.pc = pc;
			this.color = color;
		}
		public int hashCode()
		{
			return r+(3137*(c+3137*(pr+3137*(pc+3137*color))));
		}
		public boolean equals(Object obj)
		{
			State s = (State) obj;
			return r==s.r && c==s.c && pr==s.pr && pc==s.pc && color==s.color;
		}
	}
}
