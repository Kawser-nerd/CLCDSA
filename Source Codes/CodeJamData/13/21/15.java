package r1b2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int a = in.nextInt(), n = in.nextInt();
			int[] v = new int[n];
			for (int i = 0; i < n; i++) v[i] = in.nextInt();
			Arrays.sort(v);
			long ans = n, cur = 0;
			if (a > 1) {
				for (int i = 0; i < n; i++) {
					while (a <= v[i]) {
						a += a-1;
						cur++;
					}
					a += v[i];
					ans = Math.min(ans, cur + n - i - 1);
				}
			}
			out.println(ans);
		}
		
		out.flush();
	}

}
