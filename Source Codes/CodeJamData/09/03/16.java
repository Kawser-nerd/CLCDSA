import java.util.Arrays;
import java.util.Scanner;

public class C
{

	public static void main(String[] args) throws Exception
	{
		new C();
	}

	final String W = "welcome to code jam";
	final int M = 10000;

	String S;

	int[][] memo = new int[500][W.length()];

	C() throws Exception
	{
		Scanner in = new Scanner(System.in);
		for (int T = new Integer(in.nextLine()), ds = 1; T-- > 0; ++ds)
		{
			S = in.nextLine();
			for (int i = 0; i < S.length(); ++i)
				Arrays.fill(memo[i], -1);
			System.out.printf("Case #%d: %04d%n", ds, go(0, 0));
		}
	}

	int go(int s, int w)
	{
		if (w == W.length())
			return 1;
		if (s == S.length())
			return 0;
		if (memo[s][w] > -1)
			return memo[s][w];
		int res = go(s + 1, w);
		if (S.charAt(s) == W.charAt(w))
			res = (res + go(s + 1, w + 1)) % M;
		return memo[s][w] = res;
	}

}
