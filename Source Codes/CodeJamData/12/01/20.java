package qualification;

import java.io.*;

/**
 * @author Roman Elizarov
 */
public class A {
	public static void main(String[] args) throws IOException {
		new A().go();
	}

	char[] map = new char[256];

	private void go() throws IOException {
		buildMap();
		solveCase();
	}

	private void solveCase() throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("test\\qualification\\a.in"));
		PrintWriter out = new PrintWriter(new FileWriter("test\\qualification\\a.out"));
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++) {
			String s = in.readLine();
			out.print("Case #" + i + ": ");
			for (int j = 0; j < s.length(); j++)
				out.print(map[s.charAt(j)]);
			out.println();
		}
		in.close();
		out.close();
	}

	private void buildMap() throws IOException {
		map['y'] = 'a';
		map['e'] = 'o';
		map['q'] = 'z';

		BufferedReader in = new BufferedReader(new FileReader("test\\qualification\\a.sample.in"));
		int n = Integer.parseInt(in.readLine());
		String[][] a = new String[n][];
		for (int i = 0; i < n; i++)
			a[i] = in.readLine().split("\\s+");
		String[][] b = new String[n][];
		for (int i = 0; i < n; i++)
			b[i] = in.readLine().split("\\s+");
		in.close();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < a[i].length; j++) {
				assert a[i][j].length() == b[i][j].length();
				for (int k = 0; k < a[i][j].length(); k++) {
					char c = a[i][j].charAt(k);
					char d = b[i][j].charAt(k);
					assert map[c] == 0 || map[c] == d : c + "->" + d + " or " + map[c];
					map[c] = d;
				}
			}
		boolean[] u = new boolean[256];
		char c0 = 0;
		int cc = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			char d = map[c];
			if (d != 0)
				u[d] = true;
			else {
				cc++;
				c0 = c;
			}
		}
		assert cc <= 1;
		if (cc == 1) {
			for (char d = 'a'; d <= 'z'; d++)
				if (!u[d]) {
					map[c0] = d;
					break;
				}
		}
		for (char c = 'a'; c <= 'z'; c++)
			System.out.println(c + "->" + (map[c] == 0 ? "???" : "" + map[c]));
		for (char c = 0; c < map.length; c++)
			if (map[c] == 0)
				map[c] = c;
	}
}
