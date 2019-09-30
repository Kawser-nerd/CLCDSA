package r1b2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class B1
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
			int a = (x - y)/2;
			int b = (x + y)/2;
			if (b < a) {
				out.println("0.0");
				continue;
			}
			int d = Math.max(Math.abs(a), Math.abs(b));
			int tot = 1, level = 0;
			while (tot <= n) {
				level++;
				tot += 4*level + 1;
			}
			//System.out.println(a + " " + b + ", " + d + " " + tot + " " + level);
			if (d < level) {
				out.println("1.0");
				continue;
			}
			if (d > level) {
				out.println("0.0");
				continue;
			}
			if (x == 0) {
				out.println("0.0");
				continue;
			}
			
			int last = n - (tot - 4*level - 1);
			int height = b - a + 1;
			//System.out.println(last + " " + height);
			if (last >= 2*level + height) {
				out.println("1.0");
				continue;
			}
			if (last < height) {
				out.println("0.0");
				continue;
			}
			
			memo = new double[last+1][height+1];
			for (double[] mm : memo) Arrays.fill(mm, -1);
			out.println(solve(last, height));
		}
		
		out.flush();
	}
	
	static double memo[][];

	static double solve(int last, int height) {
		if (height == 0) return 1;
		if (last == 0) return 0;
		if (last < height) return 0;
		if (memo[last][height] != -1) return memo[last][height];
		return memo[last][height] = (solve(last-1, height) + solve(last-1, height-1))/2;
	}
}
