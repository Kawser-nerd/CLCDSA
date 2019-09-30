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
		int M = sc.nextInt();
		int[] gr = new int[N];
		int[][] vec = new int[N][4];
		for (int i = 0; i < M; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			if (gr[a] < 4) {
				vec[a][gr[a]] = b;
			}
			if (gr[b] < 4) {
				vec[b][gr[b]] = a;
			}
			gr[a]++;
			gr[b]++;
		}
		boolean can = true;
		int six = 0, four = 0, lastFour = -1;
		for (int i = 0; i < N; i++) {
			if (gr[i] % 2 != 0) can = false;
			if (gr[i] >= 6) six++;
			else if (gr[i] == 4) {
				four++;
				lastFour = i;
			}
		}
		if (can) {
			if (six == 0 && four < 2) can = false;
			if (six == 0 && four == 2) {
				can = false;
				for (int i = 0; i < 4; i++) {
					int prev = lastFour;
					int next = vec[lastFour][i];
					while (next != lastFour && gr[next] == 2) {
						int tmp = next;
						next = vec[next][0] + vec[next][1] - prev;
						prev = tmp;
					}
					if (next == lastFour) {
						can = true;
						break;
					}
				}
			}
		}
		out.println(can ? "Yes" : "No");
		
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