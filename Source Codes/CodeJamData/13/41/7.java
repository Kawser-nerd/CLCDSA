import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in;
	static PrintWriter ou;
	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}
//	static BufferedReader in;

	public static void main(String[] args) throws Exception {
//		in = new Scanner(System.in);
		ou = new PrintWriter(System.out);
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
//		in = new BufferedReader(new InputStreamReader(System.in));

		int tests = next();

		for (int test = 1; test <= tests; test++) {
			int n = next();
			int m = next();

			int[] x = new int[m];
			int[] y = new int[m];
			int[] p = new int[m];
			for (int i = 0; i < m; i++) {
				x[i] = next() - 1;
				y[i] = next() - 1;
				p[i] = next();
			}

			TreeSet<Integer> set = new TreeSet<Integer>();
			for (int v : x) set.add(v);
			for (int v : y) set.add(v);
			int k = set.size();
			ArrayList<Integer> st = new ArrayList<Integer>();
			int ind = 0;
			for (int v : set) st.add(v);

			long[] in = new long[k];
			long[] out = new long[k];
			for (int i = 0; i < m; i++) {
				ind = Collections.binarySearch(st, x[i]);
				in[ind] += p[i];
				ind = Collections.binarySearch(st, y[i]);
				out[ind] += p[i];
			}
			

			long mod = 1000002013;
			long answ = 0;
			for (int i = 0; i < m; i++) {
				int a1 = y[i] - x[i];
				int a2 = 2*n - a1 + 1;
				if (a1 % 2 == 0) a1 /= 2;
				else a2 /= 2;
				answ += (long) a1 * a2 % mod * p[i] % mod;
			}
			answ %= mod;
			answ = mod - answ;
			int[] stat = new int[2*m + 1];
			long[] kol = new long[2*m + 1];
			ind = 0;

			for (int i = 0; i < k; i++) {
				if (in[i] != 0) {
					stat[ind] = st.get(i);
					kol[ind] = in[i];
					ind++;
				}
				while (out[i] != 0) {
					long t = Math.min(out[i], kol[ind - 1]);
					out[i] -= t;
					kol[ind - 1] -= t;
					long add1 = st.get(i) - stat[ind - 1];
					long add2 = 2L*n - add1 + 1;
					if (add1 % 2 == 0) add1 /= 2;
					else add2 /= 2;
					answ += add1 % mod * (add2 % mod) % mod * t % mod;
					if (kol[ind - 1] == 0) ind--;
				}
			}

			answ %= mod;
			answ = mod - answ;
			answ %= mod;
			
			ou.print("Case #" + test + ": ");
			ou.println(answ);
		}

		ou.close();
	}
}