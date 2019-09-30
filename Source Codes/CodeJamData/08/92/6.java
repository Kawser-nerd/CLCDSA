import java.util.*;
import java.math.*;

public class PingPongEasy
{
	static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int cases = sc.nextInt();
		for(int caseNum=1;caseNum<=cases;caseNum++)
		{
			System.out.print("Case #"+caseNum+": ");
			int X = sc.nextInt(), Y = sc.nextInt();
			boolean[][] vis = new boolean[X][Y];
			int[][] dis = new int[2][2];
			for(int i=0;i<2;i++)
			{
				dis[i][0] = sc.nextInt();
				dis[i][1] = sc.nextInt();
			}
			int x = sc.nextInt(); int y = sc.nextInt();
			System.out.println(recurse(x, y, vis, dis));
		}
	}
	private static int recurse(int x, int y, boolean[][] vis, int[][] dis)
	{
		if(x<0 || x>=vis.length || y<0 || y>=vis[x].length || vis[x][y])
			return 0;
		vis[x][y] = true;
		int res = 1;
		for(int i=0;i<2;i++)
			res += recurse(x+dis[i][0],y+dis[i][1],vis,dis);
		return res;
	}
}
