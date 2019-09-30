import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"A-small-attempt0.in")));
		writer = new PrintWriter("A-small-attempt0.out");
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws IOException {
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			writer.print("Case #" + (t + 1) + ": ");
			solve();
		}
	}

	static void solve() throws IOException {
		int n = nextInt();
		int len = nextInt();
		int[] out = new int[n];
		int[] dev = new int[n];
		for (int i = 0; i < n; i++) {
			out[i] = Integer.parseInt(nextToken(), 2);
		}
		for (int j = 0; j < n; j++) {
			dev[j] = Integer.parseInt(nextToken(), 2);
		}

		int ans = 1000000;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sw = 0;
				int cand = 0;
				for (int bit = 0; bit < len; bit++) {
					if (((1 << bit) & out[i]) != ((1 << bit) & dev[j])) {
						sw |= (1 << bit);
						cand++;
					}
				}
				HashSet<Integer> newOut = new HashSet<>();
				for (int k = 0; k < n; k++) {
					newOut.add(out[k] ^ sw);
				}

				boolean bGood = true;
				for (int k = 0; k < n; k++) {
					if (!newOut.contains(dev[k])) {
						bGood = false;
						break;
					}
				}
				if (bGood) {
					if (cand < ans)
						ans = cand;
				}
			}
		}

		if (ans == 1000000) {
			writer.println("NOT POSSIBLE");
		} else {
			writer.println(ans);
		}
	}
}