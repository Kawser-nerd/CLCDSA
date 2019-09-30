import java.util.*;
public class d {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int n = input.nextInt();
		double[] as = new double[n], bs = new double[n];
		TreeSet<Double> second = new TreeSet<Double>();
		for(int i = 0; i<n; i++) as[i] = input.nextDouble();
		for(int i = 0; i<n; i++) bs[i] = input.nextDouble();
		for(double d: bs) second.add(d);
		Arrays.sort(as);
		Arrays.sort(bs);
		int res1 = 0, res2 = 0;
		for(int i = 0; i<n; i++)
		{
			Double cur = second.ceiling(as[i]);
			//System.out.println(cur);
			if(cur == null)
			{
				res2++;
				//System.out.println(second.first());
				second.remove(second.first());
			}
			else second.remove(cur);
		}
		res1 = 0;
		for(int elim = 0; elim <n; elim++)
		{
			int count = 0;
			for(int i = elim; i<n; i++)
			{
				if(as[i] > bs[i-elim]) count++;
			}
			res1 = Math.max(res1, count);
		}
		System.out.println(res1+" "+res2);
	}
}
}
