import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Lottery {
	static BufferedReader stdin = new BufferedReader(
			new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	// Read next input-token as string.
	static String readString() throws Exception {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}

	// Read next input-token as integer.
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}

	// Read next input-token as double.
	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
	
	public static void main(String[] args) throws Exception {
		int T = readInt();
		for (int t=1; t<=T ; t++) {
			System.out.printf("Case #%d: ", t);
			solve();
		}
	}
	static void solve() throws Exception {
		int A, B, K;
		A = readInt();
		B = readInt();
		K = readInt();
		long total = 0L;
		for (int a = 0 ; a<A ; a++) {
			for (int b = 0 ; b< B; b++) {
				if ((a&b) < K)
					total++;
			}
		}
		System.out.printf("%d\n",total);
	}
}
