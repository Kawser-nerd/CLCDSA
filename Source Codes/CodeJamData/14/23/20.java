import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class TheBoredSalesman {
	static int n, m;
	static String[] zip;
	static ArrayList<Integer>[] adj;
	static boolean[][] flights;
	static BigInteger res;

	static void go(int index, int mask, String curr, int fCount) {
		if (mask == (1 << n) - 1) {
			if (fCount == 0) {
				if (res == null)
					res = new BigInteger(curr);
				else if (res.compareTo(new BigInteger(curr)) > 0) {
					res = new BigInteger(curr);
				}
				return;
			}
		}

		for (int i = 0; i < n; i++) {
			if (flights[index][i]) {
				flights[index][i] = false;
				go(i, mask, curr, fCount - 1);
				flights[index][i] = true;
			}
		}
		for (int x : adj[index]) {
			if ((mask & (1 << x)) == 0) {
				flights[x][index] = true;
				go(x, mask | (1 << x), curr + zip[x],fCount+1);
				flights[x][index] = false;
			}
		}
	}

	static void gen() {
		n = 8;
		m = (n * (n - 1)) / 2;
		System.out.println(1);
		System.out.println(n + " " + m);
		for (int i = 0; i < n; i++) {
			System.out.println(99999);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				System.out.println((i + 1) + " " + (j + 1));
			}
		}
	}

	public static void main(String[] args) throws IOException {
		 gen();
		BufferedReader r = null;
		// r = new BufferedReader(new FileReader("CSmall.in"));
		r = new BufferedReader(new InputStreamReader(System.in));
		String line = r.readLine();
		PrintWriter out = null;
		// out = new BufferedWriter(new FileWriter("CSolution.txt"));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(line);
		int test = 1;
		while (T-- > 0) {
			String[] sp = r.readLine().split("[ ]+");
			n = new Integer(sp[0]);
			m = new Integer(sp[1]);
			zip = new String[n];
			int start = 0;
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			for (int i = 0; i < zip.length; i++) {
				zip[i] = r.readLine();
				map.put(zip[i], i);
				if(zip[i].compareTo(zip[start])<0)
					start = i;
			}
			adj = new ArrayList[n];
			for (int i = 0; i < adj.length; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < m; i++) {
				sp = r.readLine().split("[ ]+");
				int from = new Integer(sp[0]) - 1;
				int to = new Integer(sp[1]) - 1;
				adj[from].add(to);
				adj[to].add(from);
			}
			res = null;
				flights = new boolean[n][n];
				go(start, 1 << start, zip[start], 0);
//			System.out.printf("Case #%d: %s\n", test++, res.toString());
			out.printf("Case #%d: %s\n", test++, res.toString());
		}
		out.close();
	}
}
