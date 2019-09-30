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
		
		int m = 11000;
		double[][] c = new double[m][m];
		c[0][0] = 1;
		for (int i = 1; i < m; i++) {
			c[i][0] = c[i][i] = c[i - 1][0] /2;
			for(int j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) /2;
		}

		for (int test = 1; test <= tests; test++) {

			int n = next();
			int x = Math.abs(next());
			int y = Math.abs(next());

			int level = (x + y)/2;

			int sum = 0;
			int lev = 0;
			for (;; lev++) {
				sum += 4*lev + 1;
				if (sum >= n) break;
			}

			int kol = n - sum + 4*lev + 1;
			
			
			double answ = 0;
			if (level == lev) {
				if (x == 0) {
					if (kol == 4*lev + 1) answ = 1;
				} else {
//					System.out.println(kol + "!");
					for (int i = 0; i <= kol; i++)
						if (i + Math.max(0, kol - i - 2*lev) > y) {
							answ += c[kol][i];
///							System.out.println(i + " " + c[kol][i]);
						}
//					System.out.println();
				}
			} else if (level < lev) answ = 1;
			
			out.print("Case #" + test + ": ");
			out.println(answ);
		}

		out.close();
	}
}