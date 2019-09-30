import java.util.*;

public class PermRLE
{
	private static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int N = Integer.parseInt(sc.nextLine());
		for(int i=1;i<=N;i++)
		{
			K = Integer.parseInt(sc.nextLine());
			str = sc.nextLine();
			computeCosts();
			//A.apr(cost);
			//A.apr(joinCost);
			
			int res = INF;
			for(int j=0;j<K;j++)
			{
				first = j;
				res = Math.min(res, solve());
			}
			System.out.println("Case #"+i+": "+res);
		}
	}
	
	public static int solve()
	{
		memo = new int[K][1<<K];
		for(int[] arr:memo)
			Arrays.fill(arr, -1);
		
		return solve(first, 1<<first)+1;
	}
	
	public static int solve(int prev, int mask)
	{
		if(memo[prev][mask]==-1)
		{
			int count = Integer.bitCount(mask), res = INF;
			if(count == K)
			{
				res = joinCost[prev][first];
			}
			else
			{
				for(int i=0;i<K;i++)
				{
					if((mask&1<<i)==0)
					{
						res = Math.min(res,
							cost[prev][i] + solve(i, mask|1<<i));
					}
				}
			}
			memo[prev][mask] = res;
		}
		return memo[prev][mask];
	}
	
	
	static int K, M, first, INF = 10000000;
	static String str;
	static int[][] cost, joinCost, memo;
	
	public static void computeCosts()
	{
		M = str.length()/K;
		cost = new int[K][K];
		joinCost = new int[K][K];
		for(int i=0;i<K;i++)
		{
			for(int j=0;j<K;j++)
			{
				if(i==j)
					continue;
				
				for(int k=0;k<M;k++)
				{
					if(str.charAt(k*K+i)!=str.charAt(k*K+j))
					{
						cost[i][j]++;
					}
					if(k+1<M &&
						str.charAt(k*K+i)!=str.charAt(k*K+K+j))
					{
						joinCost[i][j]++;
					}
				}
			}
		}
	}
	
}
