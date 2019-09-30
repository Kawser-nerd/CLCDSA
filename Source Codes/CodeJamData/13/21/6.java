import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in;
	static PrintWriter out;
	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}
//	static BufferedReader in;

	public static void main(String[] args) throws Exception {
//		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
//		in = new BufferedReader(new InputStreamReader(System.in));

		int tests = next();

		for (int test = 1; test <= tests; test++) {

			int a = next();
			int n = next();
			int[] x = new int[n];
			for (int i = 0; i < n; i++) x[i] = next();
			Arrays.sort(x);
			int answ = n;
			if (a > 1) {
				for (int i = 0; i <= n; i++) {
//					System.out.println(i);
					int ans = n - i;
					int b = a;
					for (int j = 0; j < i; j++) {
						while (b <= x[j]) {
							ans++;
							b += b-1;
						}
						b += x[j];
					}
					answ = Math.min(answ, ans);
				}
			}
			
			out.print("Case #" + test + ": ");
			out.println(answ);
		}

		out.close();
	}
}