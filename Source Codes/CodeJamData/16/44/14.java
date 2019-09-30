import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class d {
	public static void main(String[] Args) throws Exception {
		// FS sc = new FS(new File("D-large.in"));
		 FS sc = new FS(new File("D-small-attempt1.in"));
//		FS sc = new FS(System.in);
//		PrintWriter out = new PrintWriter(new BufferedWriter(
//				new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("d.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);
			int n = sc.nextInt();
			int[][] mat = new int[n][n];
			int tt = 0;
			boolean[] used = new boolean[n];
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < n; j++) {
					mat[i][j] = s.charAt(j) - '0';
					if (mat[i][j] == 1)
						used[j] = true;
					tt += mat[i][j];
				}
			}
			int ans = 10000;
			for (int i = 0; i <= (1 << (n * n)); i++) {
				if (check1(i, n) && check2(i, mat)) {
					ans = Math.min(ans, Integer.bitCount(i));
				}

			}

			out.println(ans-tt);
		}
		out.close();
	}

	public static boolean check1(int st, int n) {
		int[] co1 = new int[n];
		int[] co2 = new int[n];
		int[][] things = new int[n][n];
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((st & (1 << c)) != 0){
					things[i][j] = 1;
					co1[i]++;
					co2[j]++;
				}
				c++;
			}
		}
		for (int i = 0; i < n; i++){
			if (co1[i] == 0 || co2[i] == 0)
				return false;
		}
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (things[i][j] == 1){
					if (co1[i] != co2[j])
						return false;
				}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int i2 = 0; i2 < n; i2++)
					for (int j2 = 0; j2 < n; j2++)
						if (things[i][j] == 1 && things[i2][j2] == 0 && things[i2][j] == 1 && things[i][j2] == 1)
							return false;
					
		return true;
	}

	public static boolean check2(int st, int[][] a) {
		int n = a.length;
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1 && (st & (1 << c)) == 0)
					return false;
				c++;
			}
		}
		return true;
	}

	public static class FS {
		BufferedReader br;
		StringTokenizer st;

		FS(InputStream in) throws Exception {
			br = new BufferedReader(new InputStreamReader(in));
			st = new StringTokenizer(br.readLine());
		}

		FS(File in) throws Exception {
			br = new BufferedReader(new FileReader(in));
			st = new StringTokenizer(br.readLine());
		}

		String next() throws Exception {
			if (st.hasMoreTokens())
				return st.nextToken();
			st = new StringTokenizer(br.readLine());
			return next();
		}

		int nextInt() throws Exception {
			return Integer.parseInt(next());
		}
	}
}
