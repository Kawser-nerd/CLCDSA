import java.util.*;

public class WorldCup
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.println("Case #"+i+": "+solveCase());
		}
	}
	static long solveCase()
	{
		N = sc.nextInt();
		req = new int[1<<N];
		for(int i=0;i<req.length;i++)
			req[i] = sc.nextInt();
		
		cost = new int[N][];
		memo = new long[N][][];
		
		for(int i=N-1;i>=0;i--)
		{
			cost[i] = new int[1<<i];
			memo[i] = new long[i+1][1<<i];
			for(long[] arr:memo[i])
				Arrays.fill(arr, -1L);
			for(int j=0;j<cost[i].length;j++)
				cost[i][j] = sc.nextInt();
		}
		return solve(0,0,0);
	}
	static int N;
	static int[] req;
	static int[][] cost;
	static long[][][] memo;
	static final long INF = Integer.MAX_VALUE * 1000L;
	
	static long solve(int index, int level, int count)
	{
		if(level >= N)
			return count >= N - req[index] ? 0 : INF;
		if(memo[level][count][index]==-1)
		{
			long skip = solve(index*2,level+1,count)+solve(index*2+1,level+1,count);
			long choose = solve(index*2,level+1,count+1)+solve(index*2+1,level+1,count+1)+cost[level][index];
			memo[level][count][index] = Math.min(skip, choose);
		}
		return memo[level][count][index];
	}
}
