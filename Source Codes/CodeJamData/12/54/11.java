import java.io.*;
import java.util.*;

public class taskD {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	void mark(char a, char b, boolean[][] need, int[] count, int[] count2) {
		if (a == 0)
			return;
		if (b == 0)
			return;
		if (need[a][b])
			return;
		need[a][b] = true;
		count[a]++;
		count2[b]++;
	}

	public void solve() throws IOException {
		int k = nextInt();
		String s = nextToken();
		int[] count = new int[256];
		char[] go = new char[256];
		boolean[][] need = new boolean[256][256];
		go['a'] = '4';
		go['s'] = '5';
		go['i'] = '1';
		go['o'] = '0';
		go['e'] = '3';
		go['t'] = '7';
		go['b'] = '8';
		go['g'] = '9';
		int[] count2 = new int[256];
		for (int i = 0; i < s.length() - 1; i++) {
			char a = s.charAt(i);
			char b = s.charAt(i + 1);
			mark(a, b, need, count, count2);
			mark(go[a], b, need, count, count2);
			mark(a, go[b], need, count, count2);
			mark(go[a], go[b], need, count, count2);
		}
		int sum = 0;
		boolean fl = false;
		boolean fl2 = false;
		for (int i = 0; i < 256; i++) {
			sum += count[i] * 2;
			sum -= Math.min(count[i], count2[i]);
			if (count[i] != count2[i])
				fl = true;
			
		}
		if (!fl)
			sum++;
		out.println(sum);
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskD.in"));
			out = new PrintWriter("taskD.out");

			int n = nextInt();
			for (int i = 0; i < n; i++) {
				out.print("Case #" + (i + 1) + ": ");

				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskD().run();
	}
}
