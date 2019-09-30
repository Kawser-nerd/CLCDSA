import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++) {
				switch (s.charAt(j)) {
				case '0':
					a[i][j] = 0;
					break;
				case '1':
					a[i][j] = 1;
					break;
				case '.':
					a[i][j] = 2;
					break;
				}
			}
		}
		int[] games = new int[n];
		int[] wins = new int[n];
		double[] wp = new double[n];
		double[] owp = new double[n];
		double[] oowp = new double[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] < 2) {
					games[i]++;
					if (a[i][j] == 1) {
						wins[i]++;
					}
				}
			}
			wp[i] = wins[i] * 1d / games[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 2) {
					continue;
				}
				owp[i] += (wins[j] - (a[j][i])) * 1d / (games[j] - 1);
			}
			owp[i] /= games[i];
		}
		out.println();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 2) {
					continue;
				}
				oowp[i] += owp[j];
			}
			oowp[i] /= games[i];
			out.println((wp[i] + 2 * owp[i] + oowp[i]) / 4);
		}
		
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
