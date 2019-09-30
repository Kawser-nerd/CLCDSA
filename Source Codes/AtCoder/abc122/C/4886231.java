import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		// ???
		FastScanner sc = new FastScanner(System.in);
        PrintWriter printWriter = new PrintWriter(System.out);
		int n = sc.nextInt();
		int q = sc.nextInt();
		String[] moji_data = sc.next().split("");
		int result_cnt=0;
		int[] ruiseki_data= new int[moji_data.length];

		// ????????AC??????????????
		for(int i=0;i<moji_data.length-1;i++) {
			if(moji_data[i].equals("A") && moji_data[i+1].equals("C")) {
				// C?????????
				ruiseki_data[i+1] = ruiseki_data[i]+1;
			}
			else {
				ruiseki_data[i+1] = ruiseki_data[i];
				
			}
		}
		for(int i=0;i<q;i++) {
			// ????????????
			int start = sc.nextInt();
			int end = sc.nextInt();
			// ?????????????AC????????
	        printWriter.printf("%d\n", ruiseki_data[end-1] - ruiseki_data[start-1]);
		}
        printWriter.close();
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