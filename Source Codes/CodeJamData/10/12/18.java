import java.util.*;

public class Smooth
{
	static Scanner sc = new Scanner(System.in);
	static int[][] memo = new int[100][257];
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.print("Case #"+i+": ");
			solveCase();
		}
	}
	static final int SPC = 256;
	static void solveCase()
	{
		del = sc.nextInt(); ins = sc.nextInt();
		maxDist = sc.nextInt(); n = sc.nextInt();
		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
		
		for(int[] arr:memo)
			Arrays.fill(arr, -1);

		System.out.println(solve(0, SPC));
	}
	static int del, ins, maxDist, n;
	static int[] arr;
	static int solve(int index, int prev)
	{
		if(index >= n)
			return 0;
		if(memo[index][prev]==-1)
		{
			int res = del + solve(index+1, prev);
			for(int val=0;val<SPC;val++)
			{
				res = Math.min(res, Math.abs(arr[index]-val) +
					insCost(val, prev) + solve(index+1,val));
			}
			memo[index][prev] = res;
		}
		return memo[index][prev];
	}
	static int insCost(int cur, int prev)
	{
		if(prev==SPC || cur==prev)
			return 0;
		if(maxDist==0)
			return 100000000;
		return ins*((Math.abs(cur-prev)+maxDist-1)/maxDist - 1);
	}
}
