import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int n = nextInt();
			int a = nextInt();
			int b = nextInt();
			int c = nextInt();
			int d = nextInt();
			int x0 = nextInt();
			int y0 = nextInt();
			int m = nextInt();
			long x = x0;
			long y = y0;
			long[] xa = new long[n];
			long[] ya = new long[n];
			xa[0] = x;
			ya[0] = y;
			for (int i = 1; i < n; i++) {
				x = (a * x + b) % m;
				y = (c * y + d) % m;
				xa[i] = x;
				ya[i] = y;
			}
			
			long[][] cnt = new long[3][3];
			for (int i = 0; i < n; i++) {
				cnt[(int) (xa[i] % 3)][(int) (ya[i] % 3)]++;
			}
			int[] xx = new int[9];
			int[] yy = new int[9];
			{
				int tmp = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						xx[tmp] = i;
						yy[tmp] = j;
						tmp++;
					}
				}
			}
			long ans = 0;
			for (int i = 0; i < 9; i++) {
				for (int j = i; j < 9; j++) {
					for (int k = j; k < 9; k++) {
						if ((xx[i] + xx[j] + xx[k]) % 3 == 0 &&
							(yy[i] + yy[j] + yy[k]) % 3 == 0) {
							if (i == j && j == k && i == k) {
								int x1 = xx[i];
								int y1 = yy[i];
								ans += cnt[x1][y1] * (cnt[x1][y1] - 1) * (cnt[x1][y1] - 2) / 6;
							} else if (i == j) {
								int x1 = xx[i];
								int y1 = yy[i];
								int x2 = xx[k];
								int y2 = yy[k];
								ans += cnt[x1][y1] * (cnt[x1][y1] - 1) / 2 * cnt[x2][y2];
							} else if (i == k) {
								int x1 = xx[i];
								int y1 = yy[i];
								int x2 = xx[j];
								int y2 = yy[j];
								ans += cnt[x1][y1] * (cnt[x1][y1] - 1) / 2 * cnt[x2][y2];
							} else if (j == k) {
								int x1 = xx[j];
								int y1 = yy[j];
								int x2 = xx[i];
								int y2 = yy[i];
								ans += cnt[x1][y1] * (cnt[x1][y1] - 1) / 2 * cnt[x2][y2];
							} else {
								int x1 = xx[i];
								int y1 = yy[i];
								int x2 = xx[j];
								int y2 = yy[j];
								int x3 = xx[k];
								int y3 = yy[k];
								ans += cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
							}
						}
					}
				}
			}
		
			out.println("Case #" + (tt + 1) + ": " + ans);
			
		}
	}
	
	void solveEasy() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int n = nextInt();
			int a = nextInt();
			int b = nextInt();
			int c = nextInt();
			int d = nextInt();
			int x0 = nextInt();
			int y0 = nextInt();
			int m = nextInt();
			long x = x0;
			long y = y0;
			long[] xa = new long[n];
			long[] ya = new long[n];
			xa[0] = x;
			ya[0] = y;
			for (int i = 1; i < n; i++) {
				x = (a * x + b) % m;
				y = (c * y + d) % m;
				xa[i] = x;
				ya[i] = y;
			}
			
			long ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					for (int k = j + 1; k < n; k++) {
						if ((xa[i] + xa[j] + xa[k]) % 3 == 0 && (ya[i] + ya[j] + ya[k]) % 3 == 0) {
							ans++;
						}
					}
				}
			}
			
			out.println("Case #" + (tt + 1) + ": " + ans);
			
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("a")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
