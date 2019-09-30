import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Q2 {

	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		int numTests = s.nextInt();
		for (int test = 0; test < numTests; test++)
		{
			double[] result = getResult(s);
			System.out.println("Case #" + (test+1) + ":");
			for (double res : result)
			{
				System.out.println(res);
			}
		}
	}
	
	private static double[] getResult(Scanner s)
	{
		double d = s.nextDouble();
		int n = s.nextInt();
		int a = s.nextInt();
		
		List<OtherCarPosition> otherCar = new ArrayList<OtherCarPosition>(n+2);
		for (int i = 0; i < n; i++)
		{
			otherCar.add(new OtherCarPosition(s.nextDouble(), s.nextDouble()));
		}
		
		for (int i = 1; i < n; i++)
		{
			OtherCarPosition pos = otherCar.get(i);
			OtherCarPosition prev = otherCar.get(i-1);
			if (pos.d > d)
			{
				double theirSpeed = (pos.d-prev.d)/(pos.t-prev.t);
				double t = (d - prev.d) / theirSpeed + prev.t;
				otherCar.add(i, new OtherCarPosition(t, d));
				break;
			}
		}
		
		double[] res = new double[a];
		for (int aIndex = 0; aIndex < a; aIndex++)
		{
			double acc = s.nextDouble();
			//System.out.println("ACC="+acc);
			double straightTime = solve(0.5*acc, 0, -d);
			double penalties = 0;
			for (int i = 0; i < otherCar.size(); i++)
			{
				OtherCarPosition pos = otherCar.get(i);
				if (pos.d > d) break;
				
				double myTime = solve(0.5*acc, 0, -pos.d);
				if (myTime + penalties < pos.t)
				{
					penalties = pos.t - myTime;
				}
			}
			res[aIndex] = straightTime + penalties;
		}
		
		return res;
	}
	
	private static double solve (double a, double b, double c)
	{
		//System.out.println(a + "t^2+" + b + "t+" + c);
		double s = (-b - Math.sqrt(b*b-4*a*c))/(2*a);
		if (s > 1e-6) return s;
		return (-b + Math.sqrt(b*b-4*a*c))/(2*a);
	}
	
	private static class OtherCarPosition
	{
		public final double t;
		public final double d;
		
		public OtherCarPosition(double t, double d)
		{
			this.t = t; this.d = d;
		}
		
		public String toString()
		{
			return "(" + t + "," + d + ")";
		}
	}
}
