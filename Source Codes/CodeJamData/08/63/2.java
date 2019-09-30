import java.util.*;

public class Millionaire
{
	static final Scanner sc = new Scanner(System.in);
	
	static double[][] memo;
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int t=1;t<=T;t++)
		{
			long cur = System.currentTimeMillis();
			System.out.print("Case #"+t+": ");
			MAX = sc.nextInt();
			P = sc.nextDouble();
			int amount = sc.nextInt();
			System.out.println(compute(amount));
			//System.err.println(System.currentTimeMillis()-cur);
		}
	}
	static int MAX;
	static double P;
	private static double compute(int amount)
	{
		memo = new double[MAX][];
		for(int i=0;i<MAX;i++)
		{
			memo[i] = new double[1<<(i+1)];
			Arrays.fill(memo[i], -1.0);
		}
		long denom = 1<<MAX;
		return solve(MAX-1,(int)(amount*denom/1000000));
	}
	
	private static double solve(int level, int amount)
	{
		if(amount>=1<<(level+1))
			return 1.0;
		if(amount==0)
			return 0.0;
		
		if(memo[level][amount]<-0.5)
		{
			double res = solve(level-1,amount/2);
			int delta = amount%2;
			for(int i=delta;i<=amount;i+=2)
			{
				res = Math.max(res,
					P*solve(level-1,(amount+i)/2)+
					(1-P)*solve(level-1,(amount-i)/2));
			}
			memo[level][amount] = res;
			//A.spr(level+":"+amount+"-->"+res);
		}
		return memo[level][amount];
	}
}
