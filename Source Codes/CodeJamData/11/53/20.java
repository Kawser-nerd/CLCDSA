import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static Scanner in; static int next() throws Exception {return in.nextInt();};
//	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;};
//	static BufferedReader in;
	static PrintWriter out;
	static String NAME = "c";
	
	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(NAME + ".in"));
//		in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));
//		in = new BufferedReader(new FileReader(new File(NAME + ".in")));
		out = new PrintWriter(new File(NAME + ".out"));
			
		int tests = next();
		
		F: for (int test = 1; test <= tests; test++) {
		
			int n = next();
			int m = next();
			char[][] c = new char[n][m];
			for (int i = 0; i < n; i++) c[i] = in.next().toCharArray();
			
			int k = n*m;
			int[][] con = new int[k][k];
			
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int i1 = i == n - 1 ? 0 : i + 1;
				int i2 = i == 0 ? n - 1 : i - 1;
				int j1 = j == m - 1 ? 0 : j + 1;
				int j2 = j == 0 ? m - 1 : j - 1;
				if (c[i][j] == '|') con[m*i1 + j][m*i2 + j]++;
				if (c[i][j] == '-') con[m*i + j1][m*i + j2]++;
				if (c[i][j] == '/') con[m*i1 + j2][m*i2 + j1]++;
				if (c[i][j] == '\\') con[m*i1 + j1][m*i2 + j2]++; 
			}
			
			for (int i = 0; i < k; i++) for (int j = 0; j < i; j++) {
				con[i][j] += con[j][i];
				con[j][i] = con[i][j];
			}
			int[] deg = new int[k];
			for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) deg[i] += con[i][j];
			
			boolean[] take = new boolean[k];
			while (true) {
				int min = 8;
				int t = -1;
				for (int i = 0; i < k; i++) if (!take[i] && min > deg[i]) {
					min = deg[i];
					t = i;
				}
				if (min == 0) {
					out.println("Case #" + test + ": 0");
					continue F;
				}
				if (min == 1) {
					take[t] = true;
					for (int i = 0; i < k; i++) if (con[i][t] > 0) {
						con[i][t]--;
						con[t][i]--;
						deg[i]--;
					}
					continue;
				}
				break;
			}
			
			int count = 0;
			for (int i = 0; i < k; i++) if (!take[i]) {
				count++;
				int t = i;
				while (!take[t]) {
//					out.print(t + " ");
					int tt = -1;
					for (int j = 0; j < k; j++) if (con[t][j] > 0) {
						tt = j;
						break;
					}
					take[t] = true;
					con[t][tt]--;
					con[tt][t]--;
					t = tt;
				}
//				out.println("---");
			}
			
			int answ = 1;
			for (int i = 0; i < count; i++) answ = (2 * answ) % 1000003;
						
			out.println("Case #" + test + ": " + answ);
			
		}
		
		out.close();
	}
	
}