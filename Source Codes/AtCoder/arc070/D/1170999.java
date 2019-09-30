import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		if (b >= a) {
			out.println("Impossible");
			out.flush();
			return;
		}
		
		int[] arr = new int[a + b];
		int sz = 0;
		
		for (int i = 0; i < a + b; i++) {
			if (sz == 0) {
				arr[sz++] = i;
				continue;
			}
			int top = arr[sz - 1];
			out.println("? " + top + " " + i);
			out.flush();
			String resp = nextToken();
			if (resp.equals("Y")) {
				arr[sz++] = i;
			} else {
				sz--;
			}
		}
		
		int honest = arr[sz - 1];
		
		char[] ans = new char[a + b];
		for (int i = 0; i < a + b; i++) {
			out.println("? " + honest + " " + i);
			out.flush();
			String resp = nextToken();
			ans[i] = resp.equals("Y") ? '1' : '0';
		}
		
		out.print("! ");
		out.println(ans);
		out.flush();
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