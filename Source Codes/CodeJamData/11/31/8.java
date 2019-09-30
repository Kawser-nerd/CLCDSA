import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws Exception {
		initFileIO(true);
		int cases = nextInt();
		for (int cas = 1; cas <= cases; cas++) {
			int R = nextInt();
			int C = nextInt();
			char[][] map = new char[R][C];
			for (int i = 0; i < map.length; i++) {
				map[i] = next().toCharArray();
			}
			boolean can = true;
			for (int i = 0; i < map.length; i++) {
				for (int j = 0; j < map[0].length; j++) {
					if (map[i][j] == '#') {
						if (i + 1 < R && j + 1 < C && map[i + 1][j] == '#' && map[i][j + 1] == '#' && map[i + 1][j + 1] == '#') {
							map[i][j] = '/';
							map[i + 1][j] = '\\';
							map[i][j + 1] = '\\';
							map[i + 1][j + 1] = '/';
						} else {
							can = false;
						}
					}
				}
			}
			System.out.println("Case #" + cas + ":");
			if (can) {
				for (char[] c : map) {
					System.out.println(new String(c));
				}
			} else {
				System.out.println("Impossible");
			}
		}
	}

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	static void initFileIO(boolean large) throws Exception {
		System.setIn(new FileInputStream("A-" + (large ? "large" : "small-attempt0") + ".in"));
		System.setOut(new PrintStream("output"));
		in = new BufferedReader(new InputStreamReader(System.in));
	}

	static String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return null;
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	static double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}
}
