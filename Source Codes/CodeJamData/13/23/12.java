import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new Thread(new C()).run();
	}
	int[][] dp;
	int[] a;
	void dfs(Node v, int x, int last, int cost) {
		if (v.getEnd()) {
			dp[x][last] = Math.min(dp[x][last], cost);
		}
		if (x == a.length)
			return;
		int c = a[x];
		if (v.getChild(c) != null) {
			dfs(v.getChild(c), x + 1, Math.min(4, last + 1), cost);
		}
		if (last == 4) {
			for (int i = 0; i < 26; ++i)
				if (v.getChild(i) != null) {
					dfs(v.getChild(i), x + 1, 0, cost + 1);
				}
		}
	}

	public void run() {
		InputReader dict = null;
		try {
			dict = new InputReader(new FileInputStream("dict"));
		}
		catch (IOException e) {
		}
		Node root = new Node();
		while (dict.hasNext()) {
			String s = dict.next();
			Node it = root;
			for (int index = 0; index < s.length(); ++index) {
				int c = s.charAt(index) - 'a';
				if (it.getChild(c) == null) {
					it.setChild(c, new Node());
				}
				it = it.getChild(c);
			}
			it.setEnd();
		}
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int testCases = in.nextInt();
		for (int index = 1; index <= testCases; ++index) {
			String s = in.next();
			int n = s.length();
			a = new int[n];
			for (int i = 0; i < n; ++i)
				a[i] = s.charAt(i) - 'a';
			dp = new int[n + 1][5];
			for (int i = 1; i <= n; ++i)
				for (int j = 0; j < 5; ++j)
					dp[i][j] = n;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < 5; ++j)
					dfs(root, i, j, dp[i][j]);
			int ret = n;
			for (int i = 0; i < 5; ++i)
				ret = Math.min(ret, dp[n][i]);
			out.println("Case #" + index + ": " + ret);
		}

		out.close();
	}
}

class Node {
	Node[] child = null;
	boolean end = false;
	void setChild(int index, Node val) {
		if (child == null)
			child = new Node[26];
		child[index] = val;
	}
	Node getChild(int index) {
		return child == null ? null : child[index];
	}
	void setEnd() {
		end = true;
	}
	boolean getEnd() {
		return end;
	}
}

class InputReader {
	BufferedReader buff;
	StringTokenizer tokenizer;

	InputReader(InputStream stream) {
		buff = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(buff.readLine());
			}
			catch (Exception e) {
				return false;
			}
		return true;
	}
	String next() {
		if (!hasNext())
			throw new RuntimeException();
		return tokenizer.nextToken();
	}
	int nextInt() { return Integer.parseInt(next()); }
	long nextLong() { return Long.parseLong(next()); }
}

