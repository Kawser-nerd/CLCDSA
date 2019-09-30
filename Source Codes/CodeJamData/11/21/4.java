package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class RPI {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("rpi.in"));
		PrintWriter out = new PrintWriter(new File("rpi.out"));
		int tt = in.nextInt();
		for (int t = 1; t <= tt; t++) {
			int n = in.nextInt();
			String[] s = new String[n];
			for (int i = 0; i < n; i++)
				s[i] = in.next();

			double[] owp = new double[n];
			for (int i = 0; i < n; i++) {
				double won = 0, total = 0, a = 0;
				owp[i] = 0;
				for (int j = 0; j < n; j++)
					if (j != i && s[i].charAt(j) != '.') {
						a++;
						won = 0;
						total = 0;
						for (int k = 0; k < n; k++)
							if (k != i && k != j) {
								if (s[j].charAt(k) == '0')
									total++;
								if (s[j].charAt(k) == '1') {
									total++;
									won++;
								}
							}
						// System.out.println(i + " " + j + " " + (won /
						// total));
						owp[i] += won / total;
					}
				owp[i] = owp[i] / a;
			}

			out.println("Case #" + t + ":");
			for (int i = 0; i < n; i++) {
				double rpi, wp = 0, oowp = 0;

				double won = 0, total = 0, a = 0;
				for (int j = 0; j < n; j++)
					if (i != j) {
						if (s[i].charAt(j) == '0')
							total++;
						if (s[i].charAt(j) == '1') {
							total++;
							won++;
						}
					}
				wp = won / total;

				for (int j = 0; j < n; j++)
					if (j != i && s[i].charAt(j) != '.') {
						a++;
						oowp += owp[j];
					}
				oowp = oowp / a;

				rpi = 0.25 * wp + 0.50 * owp[i] + 0.25 * oowp;
				// System.out.println(i + " " + wp + " " + owp[i] + " " + oowp
				// + " " + rpi);
				out.println(rpi);
			}
		}
		out.flush();
		out.close();
	}
}
