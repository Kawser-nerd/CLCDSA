package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class SafetyInNumbers {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("res.txt"));
		int t = in.nextInt();
		for (int m = 1; m <= t; m++) {
			int n = in.nextInt();
			double[] A = new double[n];
			double sum = 0;
			for (int i = 0; i < n; i++)
				sum += A[i] = in.nextDouble();
			double[] ans = new double[n];
			for (int i = 0; i < n; i++) {
				double lo = 0;
				double hi = 1;
				for (int j = 0; j < 100; j++) {
					double mid = (lo + hi) / 2;
					double score = A[i] + mid * sum;
					double needed = mid;
					for (int k = 0; k < n; k++) {
						if (k == i)
							continue;
						if ((A[k] - score) > 1e-7)
							continue;
						needed += (score - A[k]) / sum;
					}
					if ((needed - 1) > 1e-7)
						hi = mid;
					else
						lo = mid;
				}
				ans[i] = lo;
			}
			out.print("Case #" + m + ":");
			for (int i = 0; i < n; i++)
				out.print(" " + (ans[i] * 100));
			out.println();
		}
		out.flush();
		out.close();
	}
}
