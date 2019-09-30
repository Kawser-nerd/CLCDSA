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
			int n = next();
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) a[i] = next();
			for (int i = 0; i < n; i++) b[i] = next();

			boolean[][] more = new boolean[n][n];
			int[] last = new int[n + 1];
			Arrays.fill(last, -1);
			for (int i = 0; i < n; i++) {
				if (a[i] != 1) more[i][last[a[i] - 1]] = true;
				for (int j = 0; j < i; j++)
					if (a[j] >= a[i]) more[j][i] = true;
				last[a[i]] = i;
			}
			Arrays.fill(last, -1);
			for (int i = n - 1; i >= 0; i--) {
				if (b[i] != 1) more[i][last[b[i] - 1]] = true;
				for (int j = i + 1; j < n; j++)
					if (b[j] >= b[i]) more[j][i] = true;
				last[b[i]] = i;
			}

			int[] morec = new int[n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) 
					if (more[i][j]) morec[i]++;
			
			int[] x = new int[n];
			boolean[] take = new boolean[n];
			for (int i = 1; i <= n; i++) {
				int ind = 0;
				for (int j = 0; j < n; j++)
					if (!take[j] && morec[j] == 0) {
						ind = j;
						break;
					}
				x[ind] = i;
				for (int j = 0; j < n; j++)
					if (more[j][ind]) morec[j]--;
				take[ind] = true;
			}
				
			out.print("Case #" + test + ":");
			for (int i = 0; i < n; i++) out.print(" " + x[i]);
			out.println();
		}

		out.close();
	}
}