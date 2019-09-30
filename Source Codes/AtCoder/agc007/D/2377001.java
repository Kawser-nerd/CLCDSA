import java.io.*;
import java.util.*;
public class Main {
	public static void main(String args[]) {
		Solver_agc007d solver = new Solver_agc007d();
		solver.input();
		solver.solve();
	}
}

class FastScanner {
	BufferedReader br;
	StringTokenizer st;
	public FastScanner(Reader in) {
		br = new BufferedReader(in);
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
				throw new RuntimeException("Can't read more inputs.");
			}
		}
		return st.nextToken();
	}
	int nextInt() {
		return Integer.parseInt(next());
	}
	long nextLong() {
		return Long.parseLong(next());
	}
	double nextDouble() {
		return Double.parseDouble(next());
	}
	String readNextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}
}
class Solver_agc007d {
	static FastScanner in = new FastScanner(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	int n, e, T, a[];
	long f[];
	void input() {
		n = in.nextInt(); e = in.nextInt(); T = in.nextInt();
		a = new int[n + 1];
		f = new long[n + 1];
		for(int i = 1; i <= n; i++) a[i] = in.nextInt();
	}
	class DequeItem {
		DequeItem(int index_, long val_) {
			index = index_;
			val = val_;
		}
		int index;
		long val;
	}
	void solve() {
		int j_ = 1;
		long min_j_ = Long.MAX_VALUE >> 1;
		Deque<DequeItem> deque = new LinkedList<>();
		deque.offer(new DequeItem(1, f[0]));
		for(int i = 1; i <= n; i++) {
			while(2 * (a[i] - a[j_]) > T) {
				j_++;
				min_j_ = Math.min(min_j_, f[j_ - 2] - 2 * a[j_ - 1]);
			}
			f[i] = min_j_ + 2 * a[i];
			while(deque.getLast().val > f[i - 1]) deque.removeLast();
			deque.offer(new DequeItem(i, f[i - 1]));
			while(deque.getFirst().index < j_) deque.removeFirst();
			f[i] = Math.min(f[i], deque.getFirst().val + T);
		}
		out.println(f[n] + e);
		out.close();
	}
}