import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);

		int[] b = fs.nextIntArray(10);		// ????????
		int[] bp = new int[10];		// ??????????????bp[3] = 1 => 3?????1?
		int N = fs.nextInt();
		int[] a = new int[N];		// ???????

		for (int i = 0; i < 10; i++) {
			bp[b[i]] = i;
		}

		// ??
		for (int i = 0; i < N; i++) {
			// ???0, 1, 2...????????????????
			char[] temp = fs.nextLine().toCharArray() ;
			for (int j = 0; j < temp.length; j++) {
//				temp[j] = (char) bp[(temp[j]+'0')];
				// char=>int????(char) O + '0'???'0'??????????????
				temp[j] = (char)(bp[Character.getNumericValue(temp[j])] + '0');
			}
			a[i] = Integer.parseInt(String.valueOf(temp));
		}

		// sort
		Arrays.sort(a);

		// ??
		for (int i = 0; i < N; i++) {
			char[] temp = parseStr(a[i]).toCharArray();
			for (int j = 0; j < temp.length; j++) {
				temp[j] = (char)(b[Character.getNumericValue(temp[j])] + '0');
			}
			System.out.println(String.valueOf(temp));
		}

	}

	static String parseStr(int a) {
		return String.valueOf(a);
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