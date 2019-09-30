import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in; static int next() throws Exception {return in.nextInt();};
	static StreamTokenizer in; static long next() throws Exception {in.nextToken(); return (long) in.nval;}
	static PrintWriter out;
	static String NAME = "c";

	public static void main(String[] args) throws Exception {
//		in = new Scanner(new File(NAME + ".in"));
		out = new PrintWriter(new File(NAME + ".out"));
		in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));
		
		int tests = (int)next();
		
		int n = 1000005;
		int[] p = new int[n];
		boolean[] pr = new boolean[n];
		Arrays.fill(pr, true);
		pr[0] = pr[1] = false;
		int ind = 0;
		for (int i = 2; i < n; i++) if (pr[i]) {
			p[ind++] = i;
			for (int j = 2*i; j < n; j += i) pr[j] = false;
		}

		for (int test = 1; test <= tests; test++) {
			long k = next();
			if (k == 1) {
				out.println("Case #" + test + ": 0");
				continue;
			}
			int answ = 1;
			for (int i = 0; i < ind && p[i] <= k; i++) {
				long t = 1;
				answ--;
				while (t * p[i] <= k) {
					t *= p[i];
					answ++;
				}
			}


			out.println("Case #" + test + ": " + answ);
		}

		
		out.close();
	}
}