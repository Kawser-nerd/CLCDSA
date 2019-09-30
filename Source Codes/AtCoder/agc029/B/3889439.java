import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int[] nVal, freq;
	static int diff;
	
	static boolean can(int to) {
		int pot = 1;
		while (pot <= nVal[to]) pot *= 2;
		int target = pot - nVal[to];
		int left = 0, right = to + 1;
		while (left + 1 < right) {
			int med = (left + right) / 2;
			if (nVal[med] > target) right = med;
			else left = med;
		}
		if (nVal[left] == target && (left < to && freq[left] > 0 || left == to && freq[left] > 1)) {
			freq[to]--;
			freq[left]--;
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] values = new int[N];
		for (int i = 0; i < values.length; i++) {
			values[i] = sc.nextInt();
		}
		Arrays.sort(values);
		diff = 1;
		for (int i = 1; i < N; i++) {
			if (values[i] != values[i-1]) diff++;
		}
		nVal = new int[diff];
		freq = new int[diff];
		int idx = 0;
		nVal[0] = values[0];
		freq[0] = 1;
		for (int i = 1; i < N; i++) {
			if (values[i] != values[i-1]) {
				nVal[++idx] = values[i];
			}
			freq[idx]++;
		}
		int ans = 0;
		for (int i = diff - 1; i >= 0; i--) {
			while (freq[i] > 0 && can(i)) {
				ans++;
			}
		}
		out.println(ans);
		
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