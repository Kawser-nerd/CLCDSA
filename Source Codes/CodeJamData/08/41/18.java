import java.util.*;


public class CheatingBooleanTree
{
	private static final Scanner sc = new Scanner(System.in);
	private static final int AND = 1;
	private static final int OR = 0;
	public static void main(String[] args)
	{
		int N = sc.nextInt();
		for(int i=1;i<=N;i++)
		{
			M = sc.nextInt(); int V = sc.nextInt();
			gate = new int[M];
			canChange = new boolean[M];
			for(int j=0;j<M;j++)
			{
				if(2*j+1<M)
				{
					gate[j] = sc.nextInt();
					canChange[j] = sc.nextInt()==1;
				}
				else
				{
					gate[j] = sc.nextInt();
				}
			}
			memo = new int[2][M];
			for(int[] arr:memo)
				Arrays.fill(arr, -1);
			
			int res = solve(V, 0);
			String out = res==INF ? "IMPOSSIBLE" : ""+res;
			System.out.println("Case #"+i+": "+out);
		}
	}
	static int M;
	static int[][] memo;
	static int[] gate;
	static boolean[] canChange;
	static final int INF = 1000000;
	
	static int solve(int value, int node)
	{
		if(memo[value][node]==-1)
		{
			int res = INF;
			if(2*node+1<M)
			{
				if(value==0)
				{
					//Try AND
					{
						int cost = gate[node]==AND ? 0:
							canChange[node] ? 1 : INF;
						int min = Math.min(
							solve(0, 2*node+1),
							solve(0, 2*node+2));
						res = Math.min(res, min+cost);
					}
					//Try OR
					{
						int cost = gate[node]==OR ? 0:
							canChange[node] ? 1 : INF;
						cost += solve(0, 2*node+1);
						cost += solve(0, 2*node+2);
						res = Math.min(res, cost);
					}
				}
				else //value==1
				{
					//Try OR
					{
						int cost = gate[node]==OR ? 0:
							canChange[node] ? 1 : INF;
						int min = Math.min(
							solve(1, 2*node+1),
							solve(1, 2*node+2));
						res = Math.min(res, min+cost);
					}
					//Try AND
					{
						int cost = gate[node]==AND ? 0:
							canChange[node] ? 1 : INF;
						cost += solve(1, 2*node+1);
						cost += solve(1, 2*node+2);
						res = Math.min(res, cost);
					}
				}
			}
			else
			{
				if(value == gate[node])
					res = 0;
			}
			memo[value][node] = res;
		}
		return memo[value][node];
	}
}

