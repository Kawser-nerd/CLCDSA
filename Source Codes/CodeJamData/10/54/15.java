import java.util.*;

public class Sum
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
	static final int MOD = 1000000007;
	static int solveCase()
	{
		long N = sc.nextLong();
		B = sc.nextInt();
		String str = "";
		while(N>0)
		{
			str += (N%B)+" ";
			N /= B;
		}
		String[] temp = str.trim().split(" ");
		n = temp.length;
		dig = new int[n];
		for(int i=0;i<n;i++)
			dig[i] = Integer.parseInt(temp[i]);
		
		choose = new int[B+1][B+1];
		for(int i=0;i<choose.length;i++)
		{
			choose[i][0] = 1;
			for(int j=1;j<=i;j++)
				choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%MOD;
		}
		fact = new int[B+1]; fact[0] = 1;
		for(int i=1;i<fact.length;i++)
		{
			fact[i] = (int)((long)fact[i-1]*i%MOD);
		}
		
		memo = new int[2][n][B][B+1];
		for(int[][][] arr3:memo) for(int[][] arr2:arr3) for(int[] arr:arr2) Arrays.fill(arr, -1);
		
		memoInner = new int[B][B][B+1][B];
		for(int[][][] arr3:memoInner) for(int[][] arr2:arr3) for(int[] arr:arr2) Arrays.fill(arr, -1);
		
		return solve(0, 0, 0, B);
	}
	static int n, B;
	static int[][][][] memo, memoInner;
	static int[] fact, dig; static int[][] choose;
	
	static int solve(int hasZero, int col, int carry, int count)
	{
		if(col >= n)
			return hasZero==0 && carry==0 ? 1 : 0;
		if(memo[hasZero][col][carry][count]==-1)
		{
			long res = 0;
			for(int i=hasZero;i<=count;i++)
			{
				for(int cout=0;cout<B;cout++)
				{
					{
						long ways = solveInner(cout - (carry > dig[col] ? 1 : 0),
							(dig[col]+B-carry)%B, i, 1);
						if(col != 0)
						{
							if(hasZero==1)
								ways = ways*choose[count-1][i-1]%MOD;
							else
								ways = ways*choose[count][i]%MOD;
							ways = ways*fact[i]%MOD;
						}
						res = (res + ways*solve(0, col+1, cout, i)%MOD)%MOD;
					}
					if(i>0 && count>0)
					{
						long ways = solveInner(cout - (carry > dig[col] ? 1 : 0),
							(dig[col]+B-carry)%B, i-1, 1);
						if(col != 0)
						{
							if(hasZero==1)
								ways = ways*choose[count-1][i-1]%MOD;
							else
								ways = ways*choose[count][i]%MOD;
							ways = ways*fact[i]%MOD;
						}
						res = (res + ways*solve(1, col+1, cout, i)%MOD)%MOD;
					}
				}
			}
			memo[hasZero][col][carry][count] = (int)res;
		}
		return memo[hasZero][col][carry][count];
	}
	static boolean inner = false;
	static int solveInner(int carry, int sum, int count, int digit)
	{
		if(carry<0)
			return 0;
		if(digit >= B)
			return carry==0 && sum==0 && count==0 ? 1 : 0;
		if(memoInner[carry][sum][count][digit]==-1)
		{
			long res = solveInner(carry, sum, count, digit+1);
			if(count>0)
				res += solveInner(carry - (digit>sum?1:0),
					(sum+B-digit)%B, count-1, digit+1);
			memoInner[carry][sum][count][digit] = (int)(res%MOD);
			inner |= res!=0;
		}
		return memoInner[carry][sum][count][digit];
	}
}
