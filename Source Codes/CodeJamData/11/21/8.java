package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import qual2011.Kattio;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1b/A-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1b/A-small-0.in"), new FileOutputStream("src/round1b/A-small-0.out"));
		io = new Kattio(new FileInputStream("src/round1b/A-large-0.in"), new FileOutputStream("src/round1b/A-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new A().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int n = io.getInt();
		String[] res = new String[n];
		for (int i = 0; i < n; i++) {
		    res[i] = io.getWord();
		}

		double[] wp = new double[n], owp = new double[n], oowp = new double[n];
		double[][] wpe = new double[n][n];
		double[] matches = new double[n];
		for (int i = 0; i < n; i++) {
			double wins = 0, m = 0;
			for (int j = 0; j < n; j++) {
			    if (res[i].charAt(j) == '1') {
					wins++;
				}
				if (res[i].charAt(j) != '.') {
					m++;
				}
			}
			if (m > 0) {
				wp[i] = wins / m;
			}
			matches[i] = m;
			for (int j = 0; j < n; j++) {
				double owins = wins, omatches = m;
			    if (res[i].charAt(j) == '1') {
					owins--;
				}
				if (res[i].charAt(j) != '.') {
					omatches--;
				}
				if (omatches > 0) {
					wpe[i][j] = owins / omatches;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			double tot = 0;
		    for (int j = 0; j < n; j++) {
		        if (res[i].charAt(j) != '.') {
					tot += wpe[j][i];
				}
		    }
			owp[i] = tot / matches[i];
		}

		for (int i = 0; i < n; i++) {
		    double tot = 0;
			for (int j = 0; j < n; j++) {
			    if (res[i].charAt(j) != '.') {
					tot += owp[j];
				}
			}
			oowp[i] = tot / matches[i];
		}

		io.println();
		for (int i = 0; i < n; i++) {
//			io.println(wp[i] + " " + owp[i] + " " + oowp[i]);
			double result = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
			io.println(result);
		}
	}
}
