import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
	final int _intMax = Integer.MAX_VALUE; //=2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; //=9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;
	static boolean bElapsed = false;

	void solve() {
		int n = readNum();
		int[] ia = readNums();
		List<Info> l = new ArrayList<>();
		for (int i=0; i<n; i++) {
			l.add(new Info(i, ia[i]));
		}
		Collections.sort(l, new InfoComp());
		// M M
		// M-1 M
		// M M-1
		Set<Integer> s1 = new HashSet<>();
		Set<Integer> s2 = new HashSet<>();
		for (int i=0; i<n/2; i++) {
			s1.add(l.get(i).idx);
		}
		for (int i=n/2; i<n; i++) {
			s2.add(l.get(i).idx);
		}
		int m1 = l.get(n/2).val;
		int m2 = l.get(n/2-1).val;
		for (int i=0; i<n; i++) {
			if (s1.contains(i))
				pln(m1);
			else
				pln(m2);
		}
	}

	void solve1() {
		int n = readNum();
		int[] ia = readNums();
		for (int i=0; i<n; i++) {
			int[] na = new int[n-1];
			int ni=0;
			for (int j=0; j<n; j++) {
				if (i != j) {
					na[ni++] = ia[j];
				}
			}
			Arrays.sort(na);
			int mi=(n-1)/2;
			pln(na[mi]);
		}
	}

	class Info implements Comparable<Info> {
		int idx;
		int val;
		public Info(int idx, int val) {
			this.idx = idx;
			this.val = val;
		}
		public int compareTo(Info o) {
			if (idx < o.idx) return -1;
			else if (idx > o.idx) return 1;
			return 0;
		}
		public boolean equals(Object o) {
			if (o instanceof Info) {
				Info that = (Info)o;
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
			if (o1.val < o2.val) return -1;
			else if (o1.val > o2.val) return 1;
			return 0;
		}
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
	String[] readFlds() {
		String line = readLine();
		return line.split(" ");
	}
	int[] readNums() {
		String[] flds = readFlds();
		int[] nums = new int[flds.length];
		for (int i=0; i<flds.length; i++) {
			nums[i] = pint(flds[i]);
		}
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
		if (bElapsed) {
			System.err.println((end-start) + "ms");
		}
	}
}