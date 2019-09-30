import java.util.*;
import java.math.*;

public class CodeJamEasy
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
			{
				ch[i] = sc.next().toCharArray();
			}
			memo = new int[m][n][1<<n];
			for(int[][] arr2:memo)
			for(int[] arr:arr2)
				Arrays.fill(arr, -1);
			System.out.println(solve(0,0,0));
		}
	}
	static int m, n;
	static char[][] ch;
	static int[][][] memo;
	static int solve(int r, int c, int mask)
	{
		if(r>=m)
			return 0;
		if(c>=n)
			return solve(r+1,c-n,mask);
		if(memo[r][c][mask]==-1)
		{
			int res = 0, cost = 0;
			if(c>0 && (mask&1<<(c-1))!=0)
				cost++;
			if((mask&1<<c)!=0)
				cost++;
			int nmask = mask&~(1<<c);
			if(ch[r][c]!='.')
				res = Math.max(res,4-2*cost+solve(r,c+1,nmask|1<<c));
			if(ch[r][c]!='#')
				res = Math.max(res,solve(r,c+1,nmask));
			memo[r][c][mask] = res;
		}
		return memo[r][c][mask];
	}
}
