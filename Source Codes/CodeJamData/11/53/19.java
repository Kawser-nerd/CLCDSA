import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class C implements Runnable {

	
	int[][][] step;
	
	
	void prepare() {
		step = new int[256][2][2];
		step['|'][0] = new int[]{1, 0};
		step['|'][1] = new int[]{-1, 0};
		step['-'][0] = new int[]{0, 1};
		step['-'][1] = new int[]{0, -1};
		step['/'][0] = new int[]{-1, 1};
		step['/'][1] = new int[]{1, -1};
		step['\\'][0] = new int[]{1, 1};
		step['\\'][1] = new int[]{-1, -1};
	}
	
	boolean check(char[][] f, int[][] m, int[][] d) {
		for (int i = 0; i < d.length; ++i) {
			Arrays.fill(d[i], 0);
		}
		for (int i = 0; i < f.length; ++i) {
			for (int j = 0; j < f[i].length; ++j) {
				int[] stp = step[f[i][j]][m[i][j]];
				++d[(i + stp[0] + f.length) % f.length][(j + stp[1] + f[i].length) % f[i].length];
			}
		}
		for (int i = 0; i < f.length; ++i) {
			for (int j = 0; j < f[i].length; ++j) {
				if (d[i][j] != 1) {
					return false;
				}
			}
		}
		return true;
	}
	
	
	private void solve() throws IOException {
		prepare();
		int R = nextInt();
		int C = nextInt();
		char[][] f = new char[R][C];
		int[][] mp = new int[R][C];
		int[][] d = new int[R][C];
		for (int i = 0; i < R; ++i) {
			f[i] = next().toCharArray();
		}
		int mod = 1000003;
		int ans = 0;
		for (int msk = 0; msk < (1 << (R * C)); ++msk) {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					mp[i][j] = (msk >> (i * C + j)) % 2;
				}
			}
			ans += check(f, mp, d) ? 1 : 0;			
		}
		out.println(ans % mod);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	private BufferedReader br;
	private StringTokenizer st;
	private PrintWriter out;
	
	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader("input.txt"));
			st = new StringTokenizer("");
			out = new PrintWriter("out.txt");

			
			int T = nextInt();
			for (int i = 1; i <= T; ++i) {
				out.print("Case #" + i + ": ");
				solve();
				//break;
			}
			out.close();			
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
		
	}

	
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = br.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
}
