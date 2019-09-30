package contest.codejam;

import java.util.*;
import java.io.*;

public class C {

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	static int T, N, K;
	static double U;
	static double[] prob;
	
	static final double EPS = 1e-9;
	
	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		br = new BufferedReader(new FileReader("C-small-1-attempt1.in"));
		out = new PrintWriter(new FileWriter("out.txt"));

		T = readInt();
		
		for (int t = 1; t <= T; t++) {
			N = readInt();
			K = readInt();
			
			U = readDouble();
			prob = new double[N];
			for (int i = 0; i < N; i++)
				prob[i] = readDouble();
			
			double lo = 0;
			double hi = 1;
			while (hi - lo >= EPS) {
				double mid = (hi + lo) / 2;
				double total = 0;
				for (int i = 0; i < N; i++)
					if (prob[i] < mid)
						total += mid - prob[i];
				if (total > U)
					hi = mid;
				else
					lo = mid;
			}
			double ans = 1;
			for (int i = 0; i < N; i++) {
				if (prob[i] < lo) {
					prob[i] = lo;
				}
				ans *= prob[i];
			}
			out.printf("Case #%d: %f\n", t, ans);
		}
		
		out.close();
	}

	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong () throws IOException {
		return Long.parseLong(next());
	}

	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter () throws IOException {
		return next().charAt(0);
	}

	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}

