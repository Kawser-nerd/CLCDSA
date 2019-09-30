import java.util.*;

public class A
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		final double EPS = 1e-14;

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int n = scan.nextInt();

			double[] a = new double[n];
			double tot = 0;

			for(int i=0;i < n;i++)
			{
				a[i] = scan.nextInt();
				tot += a[i];
			}

			double[] ans = new double[n];

			for(int i=0;i < n;i++)
			{
				double lo = 0.0;
				double hi = 1.0;

				while(hi - lo > EPS)
				{
					double mid = (hi+lo) / 2.0;
					double points = mid * tot;
					double give = 0;

					for(int j=0;j < n;j++)
					{
						if(j == i) continue;
						give += Math.max(0, a[i]+points-a[j]);
					}

					if(give <= tot-points)
						lo = mid;
					else
						hi = mid;
				}

				ans[i] = lo*100;
			}

			System.out.print("Case #" + ca + ":");
			for(int i=0;i < n;i++)
				System.out.print(" " + ans[i]);
			System.out.println();
		}
	}
}