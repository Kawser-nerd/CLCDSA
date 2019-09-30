package round2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class GCJProblemC {

	static String input = "C-small-attempt0.in", output = "c.out";

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter ps = new BufferedWriter(
				new FileWriter(new File(output)));
		int tc = sc.nextInt();
		for (int test = 1; test <= tc; test++) {
			int n = sc.nextInt();
			int[] x1 = new int[n], x2 = new int[n], x3 = new int[n], p = new int[n];
			for (int i = 0; i < n; i++) {
				x1[i] = sc.nextInt();
				x2[i] = sc.nextInt();
				x3[i] = sc.nextInt();
				p[i] = sc.nextInt();
			}
			double smin = 0.000000, smax = 1000000;
			while (smax-smin>1e-8) {
				double mid = smax+smin;
				mid/=2;
				boolean can = true;
				for (int i = 0; i < n; i++)
					for (int j = i+1; j < n; j++) {
						int dist = Math.abs(x1[i]-x1[j]) + Math.abs(x2[i]-x2[j]) + Math.abs(x3[i]-x3[j]);
						if (!((p[i] + p[j])*mid>dist))
							can = false;
					}
				if (can)
					smax = mid;
				else
					smin = mid;
			}
			// writing output
			String result = "" + smin;
			ps.write("Case #" + test + ": " + result + "\n");
		}
		sc.close();
		ps.close();
	}

}
