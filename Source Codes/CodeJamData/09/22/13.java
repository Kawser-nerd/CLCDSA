import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {

	String test() {
		char[] s = ("0" + nextToken()).toCharArray();
		int[] cnt = new int[128];
		fori: for (int i = s.length - 1; i >= 0; i--) {
			cnt[s[i]]++;
			for (char j = (char) (s[i] + 1); j <= '9'; j++) {
				if (cnt[j] > 0) {
					s[i] = j;
					cnt[j]--;
					for (int k = i + 1; k < cnt.length; k++) {
						for (char d = '0'; d <= '9'; d++) {
							if (cnt[d] > 0) {
								s[k] = d;
								cnt[d]--;
								break;
							}
						}
					}
					break fori;
				}
			}
		}
		return new BigInteger(new String(s)).toString();
	}

	private void solve() {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #" + (i + 1) + ": " + test());
		}
	}

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	private void run() {
		try {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
			solve();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		} catch (IOException e) {
			return "";
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	public static void main(String[] args) {
		new B().run();
	}
}
