import java.util.*;
public class bb {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		double c = input.nextDouble(), f = input.nextDouble(), x = input.nextDouble();
		int start = 0, end = 300000;
		while(end - start > 5)
		{
			//System.out.println(start+" "+end);
			int mid1 = start + (end-start)/3;
			int mid2 = start + 2*(end-start)/3;
			if(time(c, f, x, mid1) > time(c, f, x, mid2)) start = mid1;
			else end = mid2;
		}
		double res = 1e18;
		for(int iter = Math.max(0, start-10); iter <= end+10; iter++) res = Math.min(res, time(c, f, x, iter));
		System.out.println(res);
	}
}
static double time(double c, double f, double x, int purchase)
{
	if(purchase < 0) return -1e18;
	double cps = 2;
	if(x < c) return x/2;
	double res = 0;
	for(int i = 0; i<purchase; i++)
	{
		res += c/cps;
		cps += f;
	}
	return res + x/cps;
}
}
