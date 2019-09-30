import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			out.format("Case #%d: ", i + 1);
			solver.solve(in, out);
		}
		
		out.close();
	}
}

class Solver {
	class Event implements Comparable<Event>{
		int x;
		int p;
		int tp;
		public Event(int x, int p, int tp) {
			this.x = x;
			this.p = p;
			this.tp = tp;
		}
		public int compareTo(Event other) {
			if (x != other.x) {
				return ((x < other.x)?(-1):(1));
			}
			if (tp != other.tp)
				return ((tp < other.tp)?(-1):(1));
			return 0;
		}
	}
	private static final long MOD = 1000002013;
	private long sum(long st, long en) {
		if (st > en)
			return 0;
		return ((st + en) * (en - st + 1) / 2) % MOD;
	}
	public void solve(InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Event> events = new ArrayList<Event>();
		long sum = 0;
		for (int i = 0; i < m; i++) {
			int o = in.nextInt();
			int e = in.nextInt();
			int p = in.nextInt();
			o--;
			e--;
			events.add(new Event(o, p, 0));
			events.add(new Event(e, p, 1));
			sum += sum(n - (e - o) + 1, n) * p % MOD;
			sum %= MOD;
		}
		Collections.sort(events);
		//System.err.println(sum);
		ArrayList<Integer> st = new ArrayList<Integer>();
		ArrayList<Integer> nm = new ArrayList<Integer>();
		long ans = 0;
		int prev = 0;
		for (Event event : events) {
			for (int i = 0; i < st.size(); i++) {
				//System.err.println(sum(n + (st.get(i) - event.x) + 1, n + (st.get(i) - prev)));
				ans += sum(n + (st.get(i) - event.x) + 1, n + (st.get(i) - prev)) * (nm.get(i) % MOD) % MOD;
				ans %= MOD;
			}
			if (event.tp == 0) {
				st.add(event.x);
				nm.add(event.p);
			} else {
				int p = event.p;
				for (int i = st.size() - 1; i >= 0; --i) {
					if (p >= nm.get(i)) {
						p -= nm.get(i);
						nm.set(i, 0);
					} else {
						nm.set(i, nm.get(i) - p);
						p = 0;
						break;
					}
				}
			}
			prev = event.x;
		}
		out.println(((sum - ans) + 2 * MOD) % MOD);
		
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
