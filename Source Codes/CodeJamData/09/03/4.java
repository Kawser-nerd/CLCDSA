package gcj2009.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class C_Welcome_to_Code_Jam {

	private static boolean SMALL = false;
	private static String PROBLEM = "C";
	public static BigInteger[][] dp = null;
	public static BigInteger MOD = BigInteger.valueOf(10000L);
	public static String welcome = "welcome to code jam";
	public static String code = "";

	public static void main(String[] args) {
		try {
			Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large"))));
			PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))));

			int N = scan.nextInt();
			scan.nextLine();
			System.out.println(String.format("%d test cases:", N));
			long start = System.currentTimeMillis(), t1, left;
			for (int CASE = 1; CASE <= N; ++CASE) {
				t1 = System.currentTimeMillis();
				System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

				String test = scan.nextLine();
				code = test;
				dp = new BigInteger[code.length()][welcome.length()];

				String res = count(0, 0).toString();
				if (res.length() > 4)
					res = res.substring(res.length() - 4);
				else {
					while (res.length() < 4)
						res = "0" + res;
				}
				pw.println(String.format("Case #%d: %s", CASE, res));
				left = (System.currentTimeMillis() - start) * (N - CASE) / CASE;
				System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
			}
			pw.close();
			scan.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static BigInteger count(int p1, int p2) {
		if (p2 == welcome.length())
			return BigInteger.ONE;
		if (p1 >= code.length() || p2 >= welcome.length())
			return BigInteger.ZERO;
		if (dp[p1][p2] != null)
			return dp[p1][p2];
		char lookFor = welcome.charAt(p2);
		BigInteger res = BigInteger.ZERO;
		for (int i = p1; i < code.length(); ++i)
			if (code.charAt(i) == lookFor)
				res = res.add(count(i + 1, p2 + 1)).mod(MOD);
		dp[p1][p2] = res;
		return dp[p1][p2];
	}
}
