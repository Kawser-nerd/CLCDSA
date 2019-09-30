import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		if (Integer.bitCount(A ^ B) % 2 == 0) {
			out.println("NO");
		} else {
			out.println("YES");
			int[] list = getList(N, A, B);
			for (int i = 0; i < list.length; i++) {
				if (i > 0) out.print(" ");
				out.print(list[i]);
			}
			out.println();
		}
		
		out.flush();
	}
	
	static int[] getList(int n, int a, int b) {
		int[] ret = getFromZero(n, a ^ b);
		for (int i = 0; i < ret.length; i++) {
			ret[i] ^= a;
		}
		return ret;
	}
	
	static int[] getFromZero(int n, int b) {
		if (n == 1) return new int[] {0, 1};
		int[] ret = new int[1<<n];
		int highBit = 1 << (n-1);
		if ((b & highBit) != 0) {
			int[] tmp = getFromZero(n - 1, 1);
			int[] tmp2 = getList(n - 1, 1, b ^ highBit);
			int idx = 0;
			for (int i = 0; i < tmp.length; i++) {
				ret[idx++] = tmp[i];
			}
			for (int i = 0; i < tmp2.length; i++) {
				ret[idx++] = tmp2[i] ^ highBit;
			}
		} else {
			int[] tmp = getFromZero(n - 1, b);
			int[] tmp2 = getFromZero(n - 1, tmp[1]);
			ret[0] = tmp[0];
			int idx = 1;
			for (int i = 0; i < tmp2.length; i++) {
				ret[idx++] = tmp2[i] ^ highBit;
			}
			for (int i = 1; i < tmp.length; i++) {
				ret[idx++] = tmp[i];
			}
		}
		return ret;
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
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