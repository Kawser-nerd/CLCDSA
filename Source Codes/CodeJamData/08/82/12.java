import java.util.*;
import java.text.*;
import java.io.*;
import java.text.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Main implements Runnable {

	static String code = "b2";

	static String inpFile = code + ".in";

	static String outFile = code + ".out";

	public static void main(String[] args) throws IOException {
		fr = new FileReader(inpFile);
		br = new BufferedReader(fr);
		out = new PrintWriter(outFile);
		con = new PrintWriter(System.out);
		new Thread(new Main()).start();
	}

	static FileReader fr;

	static BufferedReader br;

	static PrintWriter out;

	static PrintWriter con;

	static StringTokenizer st;

	void msg(String s) {
		con.println(s);
		con.flush();
	}

	static String nt() {
		while (st == null || !st.hasMoreTokens()) {
			String s = null;
			try {
				s = br.readLine();
			} catch (Exception ex) {
				s = null;
			}
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}

	int ni() {
		return Integer.parseInt(nt());
	}

	long nl() {
		return Long.parseLong(nt());
	}

	boolean eof() {
		boolean ready = false;
		try {
			ready = br.ready();
		} catch (IOException ex) {
			ready = false;
		}
		return !(ready || (st != null && st.hasMoreTokens()));
	}

	int m = 10000;

	HashMap<String, Integer> nums = new HashMap<String, Integer>();

	public class VectorComparator<T extends Comparable<T>> implements
			Comparator<T[]> {
		public int compare(T[] a, T[] b) {
			for (int i = 0; i < min(a.length, b.length); i++) {
				int cmp = a[i].compareTo(b[i]);
				if (cmp != 0)
					return cmp;
			}
			return a.length < b.length ? -1 : a.length > b.length ? 1 : 0;
		}
	}

	class RInteger implements Comparable<RInteger> {
		Integer x;

		public RInteger(Integer x) {
			this.x = x;
		}

		public int compareTo(RInteger o) {
			return -this.x.compareTo(o.x);
		}
	}

	public void solution() {
		int n = ni();
		int k = 0;
		nums.clear();
		Integer[][] a = new Integer[n][3];
		for (int i = 0; i < n; i++) {
			String col = nt();
			if (!nums.containsKey(col)) {
				nums.put(col, k++);
			}
			a[i][2] = nums.get(col);
			a[i][0] = ni();
			a[i][1] = ni();
		}
		Arrays.sort(a, new VectorComparator<Integer>());
		PriorityQueue<RInteger> q = new PriorityQueue<RInteger>();
		int last = 1;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < k; i++) {
			for (int j = i; j < k; j++) {
				for (int v = j; v < k; v++) {
					last = 1;
					int ans = 0;
					q.clear();
					for (int u = 0; last <= m;) {
						if (u < n && a[u][0] <= last) {
							if (a[u][2] == i || a[u][2] == j || a[u][2] == v) {
								q.add(new RInteger(a[u][1]));
							}
							u++;
						} else {
							if (q.isEmpty())
								break;
							while (!q.isEmpty()) {
								RInteger nx = q.poll();
								if (nx.x < last)
									continue;
								last = nx.x + 1;
								ans++;
							}
						}
					}
					if (last > m) {
						min = min(ans, min);
					}
				}
			}
		}
		if (min == Integer.MAX_VALUE)
			out.print("IMPOSSIBLE");
		else
			out.print(min);
	}

	public void run() {
		int T = ni();
		for (int i = 1; i <= T; i++) {
			out.print("Case #" + i + ": ");
			solution();
			out.println();
		}
		if (out != null)
			out.close();
		if (con != null)
			con.close();
	}
}
