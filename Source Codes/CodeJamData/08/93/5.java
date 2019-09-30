import java.util.*;
import java.math.*;

public class MineLayerEasy
{
	static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int cases = sc.nextInt();
		for(int caseNum=1;caseNum<=cases;caseNum++)
		{
			System.out.print("Case #"+caseNum+": ");
			m = sc.nextInt(); n = sc.nextInt();
			val = new int[m][n];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					val[i][j] = sc.nextInt();
			mid = m/2; res = 0;
			recurse(0, 0);
			System.out.println(res);
		}
	}
	static int m, n, mid, res, count;
	static int[][] val;
	static final int[] dr = {-1,-1,-1,0,0,0,+1,+1,+1};
	static final int[] dc = {-1,0,+1,-1,0,+1,-1,0,+1};
	static void recurse(int r, int c)
	{
		if(r>=m)
		{
			for(int i=0;i<n;i++)
				if(val[m-1][i]!=0)
					return;
			res = Math.max(res, count);
			return;
		}
		if(c>=n)
		{
			if(r==0 || val[r-1][c-1]==0)
				recurse(r+1,c-n);
			return;
		}
		//Try no bomb
		if(r==0 || c==0 || val[r-1][c-1]==0)
			recurse(r,c+1);
		
		//Try bomb
		boolean ok = r==0 || c==0 || val[r-1][c-1]==1;
		for(int i=0;i<9;i++)
		{
			int nr = r+dr[i]; int nc = c+dc[i];
			if(nr>=0 && nc>=0 && nr<m && nc<n)
				ok &= val[nr][nc]>0;
		}
		if(ok)
		{
			for(int i=0;i<9;i++)
			{
				int nr = r+dr[i]; int nc = c+dc[i];
				if(nr>=0 && nc>=0 && nr<m && nc<n)
					val[nr][nc]--;
			}
			if(r==mid)
				count++;
			recurse(r,c+1);
			if(r==mid)
				count--;
			for(int i=0;i<9;i++)
			{
				int nr = r+dr[i]; int nc = c+dc[i];
				if(nr>=0 && nc>=0 && nr<m && nc<n)
					val[nr][nc]++;
			}
		}
	}
}
