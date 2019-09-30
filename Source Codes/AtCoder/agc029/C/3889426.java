import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	
	static int[] values;
	static int N;
	static int[] digit, exp;
	static int max = 0;
	static int base;
	
	
	static boolean can() {
//		System.err.println(base);
//		System.err.println("===");
		digit = new int[N];
		exp = new int[N];
		max = -1;
		for (int i = 1; i < values.length; i++) {
			if (values[i] <= values[i-1]) {
				if (!doIt(values[i] - 1)) return false;
//				System.err.print(i + ": " + values[i] + " =>");
//				for (int j = 0; j <= max; j++) {
//					System.err.print(" " + digit[j] + " (" + exp[j] + ")");
//				}
//				System.err.println();
			}
		}
		return true;
	}
	
	static boolean doIt(int val) {
		int left = -1, right = max + 1;
		while (left + 1 < right) {
			int med = (left + right) / 2;
			if (exp[med] < val) left = med;
			else right = med;
		}
		if (right == max + 1) {
			max++;
			digit[max] = 0;
			exp[max] = val;
		}
		if (exp[right] > val) {
			digit[right] = 0;
			exp[right] = val;
		}
		max = right;
		return increment();
	}
	static boolean increment() {
		digit[max]++;
		if (digit[max] == base) {
//			System.err.println(max + " es " + exp[max]);
			if (exp[max] == 0) return false;
			if (max > 0 && exp[max - 1] == exp[max] - 1) {
				max--;
				return increment();
			} else {
				exp[max]--;
				digit[max] = 1;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		values = new int[N];
		boolean one = true;
		for (int i = 0; i < N; i++) {
			values[i] = sc.nextInt();
			if (i > 0 && values[i] <= values[i-1]) one = false;
		}
		if (one) {
			out.println(1);
			out.flush();
			return;
		}
		int left = 1, right = N;
		while (left + 1 < right) {
			base = (left + right) / 2;
			if (can()) right = base;
			else left = base;
		}
		out.println(right);
		
		out.flush();
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