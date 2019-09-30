import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TheRepeater {
	static String problem = "AL";

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		 InputReader r = new InputReader(new FileReader(problem +
		 ".in"));
		 PrintWriter out = new PrintWriter(new FileWriter(problem +
		 "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			char[][] arr = new char[n][];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = r.next().toCharArray();
			}
			int[] currIndex = new int[n];
			int res = 0;
			boolean can = true;
			loop: while (true) {
				if (currIndex[0] == arr[0].length) {
					for (int k = 0; k < n; k++)
						if (currIndex[k] != arr[k].length) {
							can = false;
							break loop;
						}
					break;
				}
				char first = arr[0][currIndex[0]];
				int[] len = new int[n];
				for (int i = 0; i < n; i++) {
					int start = currIndex[i];
					int end = start;
					while (end < arr[i].length && arr[i][end] == first)
						end++;
					currIndex[i] = end;
					len[i] = end - start;
					if (len[i] == 0) {
						can = false;
						break loop;
					}
				}
				int min = 1 << 28;
				for (int L = 1; L <= 111; L++) {
					int temp = 0;
					for (int i = 0; i < n; i++) {
						temp += Math.abs(len[i] - L);
					}
					min = Math.min(temp, min);
				}
				res += min;
			}
			if (can)
				out.printf("Case #%d: %d\n", test++, res);
			else
				out.printf("Case #%d: Fegla Won\n", test++);
		}
		 out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
