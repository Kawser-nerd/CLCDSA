import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "A-small-attempt0";
	
	String[] from = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	};
	
	String[] to = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
	};

	public void solve() throws IOException {
		char[] map = new char[26];
		Arrays.fill(map, ' ');
		map['y' - 'a'] = 'a';
		map['e' - 'a'] = 'o';
		map['q' - 'a'] = 'z';
		map['z' - 'a'] = 'q';
		for (int it = 0; it < 3; ++it) {
			for (int i = 0; i < from[it].length(); ++i) {
				char u = from[it].charAt(i);
				char v = to[it].charAt(i);
				if (u != ' ') {
					map[u - 'a'] = v;
				}
			}
		}
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			String line = in.readLine();
			out.printf("Case #%d: ", test + 1);
			for (char c : line.toCharArray()) {
				out.print(c == ' ' ? c : map[c - 'a']);
			}
			out.println();
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}