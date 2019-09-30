import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

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

	static int mod = 1000000007;
	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			Integer[] primes = MathUtils.getPrimes(n);
			int[] count = new int[primes.length];

			for (int i = 1; i <= n; i++) {
				int t = i;
				for (int j = 0; j < primes.length; j++) {
					while (t % primes[j] == 0) {
						count[j]++;
						t = t / primes[j];
					}
				}
			}

			long ans = 1;
			for (int i = 0; i < count.length; i++) {
				ans = (ans*(count[i]+1)%mod);
			}

			out.println(ans);

		}
	}

	static class MathUtils {
		public static Integer[] getPrimes (int n) {
	        boolean[] isPrime = new boolean[n+1];
	        Arrays.fill(isPrime, true);
	        isPrime[0] = isPrime[1] = false;
	        for (int i = 2; i < isPrime.length; i++) {
	            if (!isPrime[i]) continue;
	            for (int j = i + i; j < isPrime.length; j += i) {
	                isPrime[j] = false;
	            }
	        }

	        List<Integer> list = new ArrayList<>();
	        for (int i = 1; i < isPrime.length; i++) {
				if (isPrime[i]) {
					list.add(i);
				}
			}
	        return list.toArray(new Integer[list.size()]);
		}
	}

	static class ArrayUtils {
		public static Map<Integer, Integer> getCountMap(int[] array) {
			Map<Integer, Integer> map = new TreeMap<>();
			for (int x : array)
				map.merge(x, 1, Integer::sum);
			return map;
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