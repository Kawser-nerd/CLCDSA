import java.util.*;
public class a {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int n = input.nextInt();
		int p = input.nextInt(), q = input.nextInt(), r = input.nextInt(), s = input.nextInt();
		int[] data = new int[n];
		for(int i = 0; i<n; i++)
		{
			data[i] = (int)(((long)i*p+q)%r + s);
		}
		long lo = 1, hi = (long)1e13;
		while(lo < hi-1)
		{
			long mid = (lo+hi)/2;
			//System.out.println(mid);
			if(canDo(data, mid)) hi = mid;
			else lo = mid;
		}
		if(!canDo(data, lo)) lo++;
		//System.out.println(lo);
		long sum = 0;
		for(int i = 0; i<n; i++) sum += data[i];
		double res = 1.*lo/sum;
		System.out.printf("%.9f\n", 1-res);
	}
}
static boolean canDo(int[] data, long max)
{
	long count = 1, sum = 0;
	int n = data.length;
	for(int i = 0; i<n; i++)
	{
		if(data[i] > max) return false;
		sum += data[i];
		if(sum > max)
		{
			count++;
			sum = data[i];
			if(count > 3) return false;
		}
	}
	return count <= 3;
}
}
