import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		TreeSet<Pair> set = new TreeSet<>();
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			set.add(new Pair(a, b));
		}
		int ans = H;
		int canFrom = 1;
		while (!set.isEmpty() && set.first().s == 1) {
			ans = Math.min(ans, set.pollFirst().f - 1);
		}
		for (int j = 2; j <= W; j++) {
			canFrom++;
			Pair tmp = new Pair(canFrom, j);
			while (set.contains(tmp)) {
				canFrom++;
				tmp.f++;
			}
			SortedSet<Pair> next = set.tailSet(tmp);
			if (!next.isEmpty() && next.first().s == j) {
				ans = Math.min(ans, next.first().f - 1);
			}
		}
		out.println(ans);
		
		out.flush();
	}
	
	static class Pair implements Comparable<Pair> {
		int f, s;
		
		public Pair(int f, int s) {
			this.f = f;
			this.s = s;
		}
		
		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(s, o.s);
			if (cmp != 0) return cmp;
			return Integer.compare(f, o.f);
		}
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