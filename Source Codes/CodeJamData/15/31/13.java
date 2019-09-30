import java.util.*;

public class A
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int test = 1; test <= t; ++test)
		{
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			System.out.printf("Case #%d: %d\n", test, solve(r, c, w));
		}
	}
	
	public static int solve(int r, int c, int w)
	{
		int total = 0;
		total += r * (c / w);
		total += w;
		if (c % w == 0)
			total -= 1;
		return total;
	}
}