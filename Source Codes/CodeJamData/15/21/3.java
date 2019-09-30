import java.util.*;
public class a {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t =  1; t<=T; t++)
	{
		System.out.print("Case #"+t+": ");
		long n = input.nextLong();
		System.out.println(go(n));
//		long[] dp = new long[(int)n+1];
//		Arrays.fill(dp, n+1);
//		dp[0] = 0;
//		for(int i = 0; i<n; i++)
//		{
//			long cur = dp[i]+1;
//			dp[i+1] = Math.min(dp[i+1], cur);
//			long other = rev(i);
//			if(other <= n)
//				dp[(int)other] = Math.min(dp[(int)other], cur);
//		}
//		System.out.println(dp[(int)n]);
		
	}
}
static long lowerHalf(long x, boolean mid, int l)
{
	int len = (x+"").length();
	if(len <= l/2) return x;
	//System.out.println(x+" "+len);
	return Long.parseLong((x+"").substring(len/2 + (mid || len%2 == 0 ? 0 : 1)));
}
static long go(long x)
{
	if(x%10 == 0) return 1 + go(x-1);
	if(x <= 10) return x;
	long pow = 1;
	while(pow * 10 <= x) pow *= 10;
	long res = go(pow - 1) + 1;
	long lower = lowerHalf(x, true, (x+"").length());
	long upper = lowerHalf(rev(x), false, (x+"").length());
	res += lower + upper - 1;
	if(upper != 1) res++;
	return res;
}
static long sum(long x)
{
	long res = 0;
	while(x > 0)
	{
		res += x%10;
		x /= 10;
	}
	return res;
}
static long rev(long x)
{
	long res = 0;
	while(x > 0)
	{
		res *= 10;
		res += x%10;
		x /= 10;
	}
	return res;
}
}
