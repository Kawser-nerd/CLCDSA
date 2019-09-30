package CodeJam;

import java.util.*;
import java.io.*;

public class B {

	private static String inFilename = "B-large.in";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/CodeJam/" + inFilename));
		PrintWriter out = new PrintWriter(new FileWriter("src/CodeJam/output.txt"));
		int T = in.nextInt();

		for (int tt = 0; tt < T; tt++) {
			long result = 0;

			int L = in.nextInt();
			long t = in.nextLong();
			int N = in.nextInt();
			int C = in.nextInt();
			int[] a = new int[C];
			for (int i = 0; i < C; i++) {
				a[i] = in.nextInt();
			}

			int[] d = new int[N];
			for (int i = 0; i < N; i++) {
				d[i] = a[i%C];
			}

			for (int i = 0; i < N; i++) {
				if (result + d[i] * 2 <= t) {
					result += d[i] * 2;
				} else {
					int left0 = (int)(d[i] - (t - result) / 2);
					result = t;
					int[] left = new int[N-i];
					left[0] = left0;
					for (int j = 1; j < N-i; j++) {
						left[j] = d[i+j];
					}
					Arrays.sort(left);
					int j = left.length - 1;
					for (int l = 0; l < L && j >= 0; l++) {
						result += left[j--];
					}
					for (int k = j; k >= 0; k--) {
						result += left[k] * 2;
					}
					break;
				}
			}

			out.print("Case #" + (tt+1) + ": " + result + "\n");
		}

		in.close();
		out.close();
	}

}