import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

import com.sun.org.apache.xml.internal.serializer.utils.StringToIntTable;

public class C implements Runnable {

	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	int n, k;
	int[][] price;
	boolean[][] w;
	boolean[] u;
	int[] bm;
	
	private void solve() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("c.in"));
		PrintWriter pw = new PrintWriter("c.out");
		
		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			
			price = new int[n][k];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < k; j++) {
					price[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			w = new boolean[n][n];
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					boolean can = true;
					for (int p = 0; p < k; p++) {
						if (price[i][p] >= price[j][p]) {
							can = false;
							break;
						}
					}
					w[i][j] = can;
				}
			}
			
			u = new boolean[n];
			bm = new int[n];
			for (int i = 0; i < n; i++) {
				bm[i] = -1;
				u[i] = false;
			}
			
			int result = 0;
			for (int i = 0; i < n; i++) {
				Arrays.fill(u, false);
				if (pair(i)) {
					result++;
				}
			}
			
			pw.println("Case #" + test + ": " + (n - result));
		}
		
		br.close();
		pw.close();
	}

	private boolean pair(int i) {
		if (u[i]) {
			return false;
		}
		u[i] = true;
		for (int j = 0; j < n; j++) {
			if (w[i][j] && (bm[j] == -1 || pair(bm[j]))) {
				bm[j] = i;
				return true;
			}
		}
		return false;
	}

}
