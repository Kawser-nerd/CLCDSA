import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class SolA {

	public static void main(String[] args) {
		try {
			new SolA().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine(), " \n\t/");
			} catch (IOException e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() {
		return Long.parseLong(nextToken());
	}
	
	String FNAME = "A-large";
	
	boolean compare(long a, long b, long c, long d) {
		BigInteger t1 = BigInteger.valueOf(a).multiply(BigInteger.valueOf(d));
		BigInteger t2 = BigInteger.valueOf(c).multiply(BigInteger.valueOf(b));
		return t1.compareTo(t2) >= 0;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
            int n = nextInt();
            int x = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            Arrays.sort(a);
            int i = 0;
            int j = n - 1;
            int ans = 0;
            while (i <= j) {
                if (a[i] + a[j] <= x) {
                    ans++;
                    i++;
                    j--;
                } else {
                    j--;
                    ans++;
                }
            }
            out.println(ans);
        }
	}
}
