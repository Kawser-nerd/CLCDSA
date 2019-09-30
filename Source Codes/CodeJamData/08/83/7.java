import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Rainbow implements Runnable {
	private static final int modulo = 1000000009;
	private final String problemID = getClass().getName().toLowerCase() + "_large";
	private BufferedReader in;
	private PrintWriter out;
	
	private int n, c;
	private List<Integer>[] nei;
	private long[][] cnk;

	private int calc(int u, int badColours, int parent) {
		if (parent != -1 && parent != 0) {
			badColours++;
		}
		int count = 0;
		for (int v: nei[u]) {
			if (v == parent) {
				continue;
			}
			count++;
		}
		if (c - badColours < count) {
			return 0;
		}
		long result = cnk[c - badColours][count];
		for (int v: nei[u]) {
			if (v == parent) {
				continue;
			}
			result = result * calc(v, count, u);
			result = result % modulo;
		}
		return (int) result;
	}
	
	private int inverse(int u) {
		return BigInteger.valueOf(u).modInverse(BigInteger.valueOf(modulo)).intValue();
	}

	private void solveSingleTest(int testNumber) throws IOException {
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		int cc = Integer.parseInt(st.nextToken());
		nei = new List[n];
		for (int i = 0; i < n; i++) {
			nei[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(in.readLine());
			int u = Integer.parseInt(st.nextToken()) - 1;
			int v = Integer.parseInt(st.nextToken()) - 1;
			nei[u].add(v);
			nei[v].add(u);
		}
		
		long[] p = new long[n + 2];
		for (int u = 1; u < p.length; u++) {
			c = u;
			p[u] = calc(0, 0, -1);
		}
		
		long[] poly = new long[n + 1];
		long[] num = new long[n + 1];
		for (int i = 1; i <= n + 1; i++) {
			long denom = 1;
			for (int j = 1; j <= n + 1; j++) {
				if (j != i) {
					denom = (denom * (i - j)) % modulo;
				}
			}
			denom = (denom + modulo) % modulo;
			Arrays.fill(num, 0);
			num[0] = 1;
			for (int j = 1; j <= n + 1; j++) {
				if (i == j) {
					continue;
				}
				for (int k = n; k > 0; k--) {
					num[k] = (num[k - 1] - j * num[k]) % modulo;
				}
				num[0] = ((modulo - j) * num[0]) % modulo; 
			}
			long inv = inverse((int) denom);
			for (int j = 0; j <= n; j++) {
				long tmp = (num[j] * inv) % modulo;
				tmp = (tmp + modulo) % modulo;
				num[j] = tmp;
			}
			
//			for (long d = 1; d <= n + 1; d++) {
//				long result = 0;
//				for (int u = n; u >= 0; u--) {
//					result = (result * d + num[u]) % modulo;
//				}
//				System.out.print(result + " ");
//			}
//			System.out.println();

			for (int j = 0; j <= n; j++) {
				poly[j] = (poly[j] + p[i] * num[j]) % modulo;
				poly[j] = (poly[j] + modulo) % modulo;
			}
		}
		
		if (poly[n] != 0) {
			System.out.println("!!!");
		}
		
		for (long d = 1; d <= n + 1; d++) {
			long result = 0;
			for (int i = n; i >= 0; i--) {
				result = (result * d + poly[i]) % modulo;
			}
			if (result != p[(int) d]) {
				System.out.println("!!!");
			}
		}
		
		long result = 0;
		for (int i = n; i >= 0; i--) {
			result = (result * cc + poly[i]) % modulo;
		}
		
		out.println("Case #" + testNumber + ": " + result);
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + ".in")));
		out = new PrintWriter(new File(problemID + ".out"));
		
		cnk = new long[502][502];
		for (int i = 0; i < cnk.length; i++) {
			cnk[i][0] = 1;
			cnk[i][i] = 1;
			for (int j = 1; j < i; j++) {
				cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % modulo;
			}
		}
		for (int i = 0; i < cnk.length; i++) {
			long fact = 1;
			for (int j = 1; j <= i; j++) {
				fact = (fact * j) % modulo;
				cnk[i][j] = (cnk[i][j] * fact) % modulo;
			}
		}
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++) {
			System.out.println("Test " + i);
			solveSingleTest(i);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) {
		new Thread(new Rainbow()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
