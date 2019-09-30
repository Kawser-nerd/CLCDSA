import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	
	static final long MOD = 1000000007;
	static final int MAX = 200001;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] vals = new int[N];
		Set<Integer>[] got = new Set[MAX];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
			Set<Integer> gg = got[vals[i]];
			if (gg == null) {
				gg = new HashSet<>();
				got[vals[i]] = gg;
			}
			gg.add(i);
		}
		long[] table = new long[N+1];
		long[] sum = new long[MAX];
		table[N] = table[N-1] = 1;
		sum[vals[N-1]] = 1;
		for (int i = N-2; i >= 0; i--) {
			table[i] = table[i+1];
			if (vals[i] != vals[i+1]) {
				table[i] += sum[vals[i]];
				table[i] %= MOD;
				sum[vals[i]] += table[i+1];
				sum[vals[i]] %= MOD;
			}
		}
		out.println(table[0]);
		
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.