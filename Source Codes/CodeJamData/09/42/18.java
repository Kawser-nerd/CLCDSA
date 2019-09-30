import java.util.*;

public class DiggingProblem
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int t=1;t<=T;t++)
		{
			System.out.print("Case #"+t+": ");
			int res = solveCase();
			if(res<INF)
				System.out.println("Yes "+res);
			else
				System.out.println("No");
		}
	}
	static int R, C, F;
	static final int INF = 1000;
	static int[][][][] best = new int[10][6][1<<6][1<<6];
	static boolean[][][][] added = new boolean[10][6][1<<6][1<<6];
	static boolean[][] empty = new boolean[10][6];
	static int solveCase()
	{
		R = sc.nextInt(); C = sc.nextInt(); F = sc.nextInt();
		for(int i=0;i<R;i++)
		{
			String str = sc.next();
			for(int j=0;j<C;j++)
				empty[i][j] = str.charAt(j)=='.';
		}
		
		for(int i=0;i<R;i++) for(int j=0;j<C;j++)
			for(int k=0;k<1<<C;k++) for(int l=0;l<1<<C;l++)
				best[i][j][k][l] = INF;
		int res = INF;
		add(0,0,0,0,0);
		while(q.size()>0)
		{
			int r = q.remove(); int c = q.remove();
			int row = q.remove(); int next = q.remove();
			int cost = best[r][c][row][next];
			added[r][c][row][next] = false;
			if(cost>=res)
				continue;
			//A.spr(r+":"+c+":"+row+":"+next+":"+cost);
			if(r+1==R)
			{
				res = Math.min(res, cost);
				continue;
			}
			if(isEmpty(r+1,c,next))
			{
				int fall = 0;
				while(r+1<R && isEmpty(r+1,c,next))
				{
					r++; fall++;
					row = next;
					next = 0;
				}
				if(fall<=F)
					addFront(r,c,row,next,cost);
			}
			else
			{
				if(isEmpty(r,c+1,row))
					addFront(r,c+1,row,next,cost);
				if(isEmpty(r,c-1,row))
					addFront(r,c-1,row,next,cost);
				if(c+1<C && !isEmpty(r+1,c+1,next) && isEmpty(r,c+1,row))
					add(r,c,row,next|1<<(c+1),cost+1);
				if(c-1>=0 && !isEmpty(r+1,c-1,next) && isEmpty(r,c-1,row))
					add(r,c,row,next|1<<(c-1),cost+1);
			}
		}
		return res;
	}
	static boolean isEmpty(int r, int c, int mask)
	{
		return c>=0 && c<C && (empty[r][c] || (mask>>c&1)==1); 
	}
	static LinkedList<Integer> q = new LinkedList<Integer>();
	static void add(int r, int c, int row, int next, int cost)
	{
		if(best[r][c][row][next]>cost)
		{
			best[r][c][row][next] = cost;
			if(!added[r][c][row][next])
			{
				added[r][c][row][next] = true;
				q.add(r); q.add(c); q.add(row); q.add(next);
			}
		}
	}
	static void addFront(int r, int c, int row, int next, int cost)
	{
		if(best[r][c][row][next]>cost)
		{
			best[r][c][row][next] = cost;
			if(!added[r][c][row][next])
			{
				added[r][c][row][next] = true;
				q.addFirst(next);
				q.addFirst(row);
				q.addFirst(c);
				q.addFirst(r); 
			}
		}
	}
}
