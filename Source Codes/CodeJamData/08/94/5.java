import java.util.*;
import java.math.*;

public class BridgeBuilders
{
	static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int cases = sc.nextInt();
		for(int caseNum=1;caseNum<=cases;caseNum++)
		{
			System.out.print("Case #"+caseNum+": ");
			m = sc.nextInt(); n = sc.nextInt();
			ch = new char[m][];
			for(int i=0;i<m;i++)
				ch[i] = sc.next().toCharArray();
			
			cost = new int[m][n];
			for(int[] arr:cost)
				Arrays.fill(arr, INF);
			
			best = new int[m][n];
			for(int[] arr:best)
				Arrays.fill(arr, INF);
			
			pred = new int[m][n];
			done = new boolean[m][n];
			int res = 0;
			bfs(0,0);
			while(true)
			{
				int bestR = -1, bestC = -1, bestVal = INF;
				for(int i=0;i<m;i++)
					for(int j=0;j<n;j++)
						if(ch[i][j]=='T' && !done[i][j] && cost[i][j]<bestVal)
						{
							bestVal = cost[i][j];
							bestR = i; bestC = j;
						}
				if(bestVal==INF)
					break;
				int tr = bestR, tc = bestC;
				best[bestR][bestC] = 0; done[bestR][bestC] = true;
				res += bestVal;
				while(pred[bestR][bestC]!=-1)
				{
					int prevR = pred[bestR][bestC]/n;
					int prevC = pred[bestR][bestC]%n;
					if(!done[prevR][prevC])
					{
						res += cost[prevR][prevC];
						done[prevR][prevC] = true;
						bestR = prevR; bestC = prevC;
					}
					else
						break;
				}
				bfs(tr, tc);
			}
			
			best[0][0] = 0;
			spanned = new boolean[m][n];
			while(true)
			{
				int bestR = -1, bestC = -1, bestVal = INF;
				for(int i=0;i<m;i++)
					for(int j=0;j<n;j++)
						if(!spanned[i][j] && best[i][j]<bestVal)
						{
							bestVal = best[i][j];
							bestR = i; bestC = j;
						}
				if(bestVal==INF)
					break;
				if(!done[bestR][bestC])
					res += bestVal;
				spanned[bestR][bestC] = true;
				update(bestR+1,bestC,bestVal+1);
				update(bestR-1,bestC,bestVal+1);
				update(bestR,bestC+1,bestVal+1);
				update(bestR,bestC-1,bestVal+1);
			}
			System.out.println(res);
		}
	}
	static void bfs(int r, int c)
	{
		q.clear();
		add(r,c,0,-1);
		while(q.size()>0)
		{
			r = q.remove();
			c = q.remove();
			add(r+1,c,cost[r][c]+1,r*n+c);
			add(r-1,c,cost[r][c]+1,r*n+c);
			add(r,c+1,cost[r][c]+1,r*n+c);
			add(r,c-1,cost[r][c]+1,r*n+c);
		}
	}
	static int m, n, INF = 1000000;
	static char[][] ch;
	static int[][] cost, best, pred;
	static boolean[][] done, spanned;
	static Queue<Integer> q = new LinkedList<Integer>();
	static void add(int r, int c, int cost_, int pred_)
	{
		if(r>=0 && r<m && c>=0 && c<n && ch[r][c]!='.' && cost_<cost[r][c])
		{
			q.add(r); q.add(c);
			cost[r][c] = cost_;
			pred[r][c] = pred_;
		}
	}
	static void update(int r, int c, int best_)
	{
		if(r>=0 && r<m && c>=0 && c<n && ch[r][c]!='.' && best_<best[r][c])
			best[r][c] = best_;
	}
}
