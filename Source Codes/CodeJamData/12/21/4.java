import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class SafetyInNumbers {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("safety.in"));
		PrintWriter out = new PrintWriter("safety.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ":");
			solve(in, out);
		}
		out.close();
	}

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		double[] answer = new double[n];
		int sum = 0;
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			sum += a[i];
		}
		for (int i = 0; i < n; i++) {
			double l = 0;
			double r = 1;
			for (int j = 0; j < 100; j++) {
				double m = (l + r) * .5;
				double currentMan = a[i] + m * sum;
				double all = m;
				for (int k = 0; k < n; k++) {
					if (k == i) {
						continue;
					}
					all += max(0, (currentMan - a[k]) / sum);
				}
				if (all > 1) {
					r = m;
				} else {
					l = m;
				}
			}
			answer[i] = (l + r) * 50;
		}
		for (double e : answer) {
			out.print(" " + e);
		}
		out.println();
	}
}
