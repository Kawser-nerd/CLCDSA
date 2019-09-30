import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static int INF = 1 << 30;
	static int modP = 1000000007;

	static class TaskX {
		int maxN = 100001;
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[] a = in.nextIntArray(n);
			Arrays.sort(a);

			int[] nums = new int[maxN];
			for (int i : a) {
				nums[i]++;
			}

			for (int i = 0; i < nums.length; i++) {
				if (nums[i] >= 3 && nums[i] % 2 == 1) {
					nums[i] = 1;
				} else if (nums[i] >= 3 && nums[i] % 2 == 0) {
					nums[i] = 2;
				}
			}

			int count = 0;
			for (int i : nums) {
				if (i == 2) {
					count++;
				}
			}

			long sum = 0;
			for (int i : nums) {
				sum += i;
			}
			if (count % 2 == 0) {
				sum -= count;
			} else {
				sum -= count+1;
			}

			System.out.println(sum);
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public double nextDouble() {
			return Double.parseDouble(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}

	}

}