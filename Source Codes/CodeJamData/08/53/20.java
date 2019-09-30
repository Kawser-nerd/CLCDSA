import java.util.*;

public class NoCheating
{
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		int C = sc.nextInt();
		for(int c=1;c<=C;c++)
		{
			M = sc.nextInt();
			N = sc.nextInt();
			
			ch = new char[M][];
			for(int i=0;i<M;i++)
				ch[i] = sc.next().toCharArray();
			
			memo = new int[2][2][M][N][1<<N];
			for(int[][][][] arr4:memo)
			for(int[][][] arr3:arr4)
			for(int[][] arr2:arr3)
			for(int[] arr:arr2)
				Arrays.fill(arr, -1);
			
			System.out.println("Case #"+c+": "+solve(0,0,0,0,0));
		}
	}
	static int M, N;
	static int[][][][][] memo;
	static char[][] ch;
	static int solve(int prevUp, int prev, int r, int c, int mask)
	{
		if(c>=N)
			return solve(0,0,r+1,0,mask);
		if(r>=M)
			return 0;
		if(memo[prevUp][prev][r][c][mask]==-1)
		{
			int res = solve(get(mask,c),0,r,c+1,set(mask,c,0));
			if(ch[r][c]=='.' && prevUp==0 && prev==0 &&
				get(mask,c+1)==0)
			{
				res = Math.max(res, 1+
					solve(get(mask,c),1,r,c+1,set(mask,c,1)));
			}
			memo[prevUp][prev][r][c][mask] = res;
		}
		return memo[prevUp][prev][r][c][mask];
	}
	static int get(int mask, int i)
	{
		return (mask>>i)&1;
	}
	static int set(int mask, int i, int val)
	{
		mask &= ~(1<<i);
		if(val==1)
			mask |= 1<<i;
		return mask;
	}
}
