import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Main {
	final int _intMax = Integer.MAX_VALUE; // =2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; // =9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;
	static boolean bElapsed = false;

	void solve() {
		Counter c = new Counter();
		int[] ia = readNums();
		int n = ia[0];
		int k = ia[1];
		int[] ib = readNums();
		for (int i = 0; i < ib.length; i++) {
			c.add(ib[i]);
		}
		List<Info> l = new ArrayList<>();
		for (Object o : c.keySet()) {
			int key = (Integer) o;
			l.add(new Info(key, c.get(o)));
		}
		Collections.sort(l, new InfoComp());
		Collections.reverse(l);
		int ans = 0;
		while (l.size() > k) {
			ans += l.get(l.size() - 1).val;
			l.remove(l.size() - 1);
		}
		pln(ans);
	}

	class Info implements Comparable<Info> {
		int idx;
		int val;

		public Info(int idx, int val) {
			this.idx = idx;
			this.val = val;
		}

		public int compareTo(Info o) {
			if (idx < o.idx)
				return -1;
			else if (idx > o.idx)
				return 1;
			return 0;
		}

		public boolean equals(Object o) {
			if (o instanceof Info) {
				Info that = (Info) o;
				return 0 == compareTo(that);
			}
			return false;
		}

		public int hashCode() {
			return idx + (val * 31);
		}

		public String toString() {
			return "(" + idx + ", " + val + ")";
		}
	}

	class InfoComp implements Comparator<Info> {
		public int compare(Info o1, Info o2) {
			if (o1.val < o2.val)
				return -1;
			else if (o1.val > o2.val)
				return 1;
			return 0;
		}
	}

	class Counter {
		Map<Object, Integer> map = new HashMap<>();

		public void add(Object o) {
			Integer v = map.get(o);
			if (v == null)
				map.put(o, 1);
			else
				map.put(o, v + 1);
		}

		public int get(Object o) {
			Integer v = map.get(o);
			if (v == null)
				return 0;
			else
				return v;
		}

		public Set<Object> keySet() {
			return map.keySet();
		}
	}

	int abs(int a) {
		return (a >= 0) ? a : -a;
	}

	long abs(long a) {
		return (a >= 0) ? a : -a;
	}

	int max(int a, int b) {
		return (a > b) ? a : b;
	}

	long max(long a, long b) {
		return (a > b) ? a : b;
	}

	int min(int a, int b) {
		return (a < b) ? a : b;
	}

	long min(long a, long b) {
		return (a < b) ? a : b;
	}

	int pint(String s) {
		return Integer.parseInt(s);
	}

	long plong(String s) {
		return Long.parseLong(s);
	}

	String readLine() {
		try {
			return _in.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int readNum() {
		String line = readLine();
		return pint(line);
	}

	long readLong() {
		String line = readLine();
		return plong(line);
	}

	String[] readFlds() {
		String line = readLine();
		return line.split(" ");
	}

	int[] readNums() {
		String[] flds = readFlds();
		int[] nums = new int[flds.length];
		for (int i = 0; i < flds.length; i++)
			nums[i] = pint(flds[i]);
		return nums;
	}

	long[] readLongs() {
		String[] flds = readFlds();
		long[] nums = new long[flds.length];
		for (int i = 0; i < flds.length; i++)
			nums[i] = pint(flds[i]);
		return nums;
	}

	void p(char c) {
		_out.print(c);
	}

	void pln(char c) {
		_out.println(c);
	}

	void p(double d) {
		_out.print(d);
	}

	void pln(double d) {
		_out.println(d);
	}

	void p(long l) {
		_out.print(l);
	}

	void pln(long l) {
		_out.println(l);
	}

	void p(String s) {
		_out.print(s);
	}

	void pln(String s) {
		_out.println(s);
	}

	static BufferedReader _in;
	static PrintWriter _out;

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		_in = new BufferedReader(new InputStreamReader(System.in));
		_out = new PrintWriter(System.out);
		new Main().solve();
		_out.flush();
		long end = System.currentTimeMillis();
		if (bElapsed)
			System.err.println((end - start) + "ms");
	}
}