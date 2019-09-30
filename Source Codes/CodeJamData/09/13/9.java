import java.util.*;
import static java.lang.Math.*;

public class C
{
	void p(String s)
	{
		System.out.println(s);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int zz = 1; zz <= T;zz++)
		{
			C = sc.nextInt();
			N = sc.nextInt();
			dp = new double[C+1];
				Arrays.fill(dp,-1.0);
			System.out.println("Case #"+zz+": "+dp(0));
			//System.out.println(choose(40,20));
		}
	}
	static int C,N;
	static double[] dp;
	public static double dp(int numDiff)
	{
		if(numDiff >= C)
			return 0.0;
		if(dp[numDiff] != -1.0)
			return dp[numDiff];
		double pr0 = ((double)choose(numDiff,N))/choose(C,N);
		double ev = 0.0;
		for(int i  = 1; i <= N;i++)
		{
			//System.out.println(numDiff+" "+i+" "+(((double)choose(numDiff,N-i)*choose(C-numDiff,i)))/(choose(C,N)));
			ev += (1.0+dp(numDiff+i))*(((double)choose(numDiff,N-i)*choose(C-numDiff,i)))/(choose(C,N));
		}
		double ans = (pr0+ev)/(1-pr0);
		dp[numDiff] = ans;
		//System.out.println(numDiff+" "+ans);
		return ans;
	}
	public static long choose(int n, int k)
	{
		long ans =1;
		ArrayList<Integer> toDiv = new ArrayList<Integer>();
		for(int i = 2; i<= k;i++)
			toDiv.add(i);
		for(int i = n;i >= n-k+1;i--)
		{
			ans *= i;
			for(int j = 0; j < toDiv.size();j++)
			{
				if(ans % toDiv.get(j) == 0)
				{
					ans/= toDiv.get(j);
					toDiv.remove(j);
					j--;
				}
			}
		}
		return ans;
	}
}
