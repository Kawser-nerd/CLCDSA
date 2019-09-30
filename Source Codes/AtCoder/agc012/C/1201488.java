import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void go(ArrayDeque<Integer> q, long x) {
		if (x == 1) {
			return;
		}
		if (x % 2 == 0) {
			go(q, x / 2);
			q.addLast(q.size() + 1);
		} else {
			go(q, x - 1);
			q.addFirst(q.size() + 1);
		}
	}
	
	void solve() throws IOException {
		long x = nextLong() + 1;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		go(q, x);
		
		List<Integer> ans = new ArrayList<>();
		for (int i = 1; i <= q.size(); i++) {
			ans.add(i);
		}
		
		ans.addAll(q);
		out.println(ans.size());
		for (int xx : ans) {
			out.print(xx + " ");
		}
		out.println();
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}