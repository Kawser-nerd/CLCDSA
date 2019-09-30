package Rnd1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Garbeled {
	static Trie T = new Trie();
	static String s;
	static int[][] DP;
	static int inf = (int) 1e9;

	static int get(int index, int left) {
		if (index == s.length())
			return 0;
		if (DP[index][left] != -1)
			return DP[index][left];
		int res = inf;
		for (int i = 1; i <= 10 && index + i <= s.length(); i++) {
			int[] temp = T.match(s.substring(index, index + i), left);
			for (int j = 0; j < 5; j++)
				if (temp[j] < inf)
					res = Math.min(res, temp[j] + get(index + i, j));
		}
		return DP[index][left] = res;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"input.in")));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		while (true) {
			String s = in.readLine();
			if (s == null)
				break;
			T.insert(s);
		}
		in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		for (int m = 1; m <= t; m++) {
			s = in.readLine();
			DP = new int[s.length() + 1][5];
			for (int i = s.length() - 1; i >= 0; i--)
				for (int j = 0; j < 5; j++) {
					DP[i][j] = inf;
					for (int k = 1; k <= 10 && i + k <= s.length(); k++) {
						int[] temp = T.match(s.substring(i, i + k), j);
						for (int kk = 0; kk < 5; kk++)
							if (temp[kk] < inf)
								DP[i][j] = Math.min(DP[i][j], temp[kk]
										+ DP[i + k][kk]);
					}
				}
			out.println("Case #" + m + ": " + DP[0][0]);
		}
		out.flush();
		out.close();
	}
}

class Trie {
	Trie[] next;
	boolean end;

	public Trie() {
		next = new Trie[26];
	}

	public void insert(String s) {
		insert(0, s);
	}

	private void insert(int index, String s) {
		if (index == s.length()) {
			end = true;
			return;
		}
		int cur = s.charAt(index) - 'a';
		if (next[cur] == null)
			next[cur] = new Trie();
		next[cur].insert(index + 1, s);
	}

	public boolean search(String s) {
		return search(0, s);
	}

	private boolean search(int index, String s) {
		if (index == s.length())
			return true;
		int cur = s.charAt(index) - 'a';
		return next[cur] != null && next[cur].search(index + 1, s);
	}

	public int[] match(String s, int cnt) {
		return match(0, s, cnt);
	}

	private int[] match(int index, String s, int cnt) {
		int inf = (int) 1e9;
		int[] ret = new int[5];
		for (int i = 0; i < 5; i++)
			ret[i] = inf;
		if (index == s.length()) {
			if (end)
				ret[cnt] = 0;
			return ret;
		}

		int cur = s.charAt(index) - 'a';
		if (next[cur] != null) {
			int[] temp = next[cur].match(index + 1, s, Math.max(cnt - 1, 0));
			for (int i = 0; i < 5; i++)
				ret[i] = Math.min(ret[i], temp[i]);
		}
		for (int i = 0; i < 26; i++)
			if (i != cur && cnt == 0 && next[i] != null) {
				int[] temp = next[i].match(index + 1, s, 4);
				for (int j = 0; j < 5; j++)
					ret[j] = Math.min(ret[j], temp[j] + 1);
			}
		return ret;
	}
}