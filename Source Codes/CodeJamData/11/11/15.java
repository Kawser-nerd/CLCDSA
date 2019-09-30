import java.util.*;

public class A
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=0;ca < T;ca++)
		{
			long n = scan.nextLong();
			int pd = scan.nextInt();
			int pg = scan.nextInt();



			boolean good = false;
			boolean bad = false;

			if(100 / gcd(100,pd) <= n)
				good = true;

			

				if(pg == 100 && pd != 100)
					bad = true;

				if(pg == 0 && pd != 0)
					bad = true;

			

			System.out.println("Case #" + (ca+1) + ": " + (good && !bad ? "Possible" : "Broken"));
		}
	}


	public static long gcd(long a, long b)
	{
		if(b == 0)
			return a;

		return gcd(b, a%b);
	}
}