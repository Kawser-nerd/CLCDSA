import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);

		String line = sc.nextLine();

		int[] num = new int[4];
		StringBuilder sb = new StringBuilder();

		num[0] = Character.getNumericValue(line.charAt(0));
		num[1] = Character.getNumericValue(line.charAt(1));
		num[2] = Character.getNumericValue(line.charAt(2));
		num[3] = Character.getNumericValue(line.charAt(3));

		// A [0] B [1] C [2] D
		// ???????????
		for (int i = 0; i < (1<<3); i++) {
			int sum = num[0];
			for (int j = 0; j < 3; j++) {
				if ((i & (1<<j)) != 0) {
					sum -= num[j+1];
				} else {
					sum += num[j+1];
				}
			}

			if (sum == 7) {
				sb.append(num[0]);
				for (int j = 0; j < 3; j++) {
					if ((i & (1<<j)) != 0) {
						sb.append("-").append(num[j+1]);
					} else {
						sb.append("+").append(num[j+1]);
					}
				}
				sb.append("=7");
				break;
			}
		}

		System.out.println(sb.toString());
	}

	static class FastScanner {

		private BufferedReader reader = null;
	    private StringTokenizer tokenizer = null;

	    public FastScanner(InputStream in) {
	        reader = new BufferedReader(new InputStreamReader(in));
	        tokenizer = null;
	    }

	    public String next() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                tokenizer = new StringTokenizer(reader.readLine());
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }
	        return tokenizer.nextToken();
	    }

	    public String nextLine() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                return reader.readLine();
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }

	        return tokenizer.nextToken("\n");
	    }

	    public long nextLong() {
	        return Long.parseLong(next());
	    }

	    public int nextInt() {
	        return Integer.parseInt(next());
	    }

	    public double nextDouble() {
	         return Double.parseDouble(next());
	     }

	    public int[] nextIntArray(int n) {
	        int[] a = new int[n];
	        for (int i = 0; i < n; i++)
	            a[i] = nextInt();
	        return a;
	    }

	    public long[] nextLongArray(int n) {
	        long[] a = new long[n];
	        for (int i = 0; i < n; i++)
	            a[i] = nextLong();
	        return a;
	    }

	}


}