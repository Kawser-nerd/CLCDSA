import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
	final int _intMax = Integer.MAX_VALUE; // =2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; // =9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;

	void solve() {
		List<Integer> la = new ArrayList<>();
		List<Integer> lb = new ArrayList<>();
		List<Integer> lc = new ArrayList<>();
		int n = readNum();
		int[] ia = readNums();
		for (int i = 0; i < ia.length; i++) {
			la.add(ia[i]);
		}
		Collections.sort(la);
		int[] ib = readNums();
		for (int i = 0; i < ib.length; i++) {
			lb.add(ib[i]);
		}
		Collections.sort(lb);
		int[] ic = readNums();
		for (int i = 0; i < ic.length; i++) {
			lc.add(ic[i]);
		}
		Collections.sort(lc);
		long ans = 0;
		int pre = -1;
		long precnt = -1;
		for (int i = 0; i < lb.size(); i++) {
			int v = lb.get(i);
			if (pre >= 0 && pre == v) {
				ans += precnt;
			} else {
				long cnta = smallSearch(la, v);
				long cntc = bigSearch(lc, v);
				ans += cnta * cntc;
				pre = v;
				precnt = cnta * cntc;
			}
		}
		pln(ans);
	}

	int smallSearch(List<Integer> list, int v) {
		int l = 0;
		int r = list.size() - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int vv = list.get(m);
			if (v <= vv)
				r = m - 1;
			else
				l = m + 1;
		}
		if (l >= list.size())
			l = list.size() - 1;
		while (l >= 0 && list.get(l) >= v)
			l--;
		return l + 1;
	}

	int bigSearch(List<Integer> list, int v) {
		int l = 0;
		int r = list.size() - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int vv = list.get(m);
			if (vv <= v - 1)
				l = m + 1;
			else
				r = m - 1;
		}
		if (r < 0)
			r = 0;
		while (r < list.size() && list.get(r) <= v)
			r++;
		return list.size() - r;
	}

	void solve3() {
		List<Integer> la = new ArrayList<>();
		List<Integer> lb = new ArrayList<>();
		List<Integer> lc = new ArrayList<>();
		int n = readNum();
		int[] ia = readNums();
		for (int i = 0; i < ia.length; i++) {
			la.add(ia[i]);
		}
		Collections.sort(la);
		int[] ib = readNums();
		for (int i = 0; i < ib.length; i++) {
			if (la.get(0) < ib[i])
				lb.add(ib[i]);
		}
		Collections.sort(lb);
		int[] ic = readNums();
		for (int i = 0; i < ic.length; i++) {
			if (lb.get(0) < ic[i])
				lc.add(ic[i]);
		}
		Collections.sort(lc);
		for (int i = lb.size() - 1; i >= 0; i--) {
			if (lc.get(lc.size() - 1) <= lb.get(i))
				lb.remove(i);
			else
				break;
		}
		for (int i = la.size() - 1; i >= 0; i--) {
			if (lb.get(lb.size() - 1) <= la.get(i))
				la.remove(i);
			else
				break;
		}
		long ans = 0;
		for (int i = 0; i < la.size(); i++) {
			int p = la.get(i);
			for (int j = 0; j < lb.size(); j++) {
				int q = lb.get(j);
				if (p < q) {
					for (int k = 0; k < lc.size(); k++) {
						int r = lc.get(k);
						if (q < r) {
							ans += lc.size() - k;
							break;
						}
					}
				}
			}
		}
		pln(ans);
	}

	void solve2() {
		List<Integer> la = new ArrayList<>();
		List<Integer> lb = new ArrayList<>();
		List<Integer> lc = new ArrayList<>();
		int n = readNum();
		int[] ia = readNums();
		for (int i = 0; i < ia.length; i++) {
			la.add(ia[i]);
		}
		Collections.sort(la);
		int[] ib = readNums();
		for (int i = 0; i < ib.length; i++) {
			lb.add(ib[i]);
		}
		Collections.sort(lb);
		int[] ic = readNums();
		for (int i = 0; i < ic.length; i++) {
			lc.add(ic[i]);
		}
		Collections.sort(lc);
		long ans = 0;
		for (int i = 0; i < la.size(); i++) {
			int p = la.get(i);
			for (int j = 0; j < lb.size(); j++) {
				int q = lb.get(j);
				if (p < q) {
					for (int k = 0; k < lc.size(); k++) {
						int r = lc.get(k);
						if (q < r) {
							ans += lc.size() - k;
							break;
						}
					}
				}
			}
		}
		pln(ans);
	}

	void solve1() {
		List<Integer> la = new ArrayList<>();
		List<Integer> lb = new ArrayList<>();
		List<Integer> lc = new ArrayList<>();
		int n = readNum();
		int[] ia = readNums();
		for (int i = 0; i < ia.length; i++) {
			la.add(ia[i]);
		}
		Collections.sort(la);
		int[] ib = readNums();
		for (int i = 0; i < ib.length; i++) {
			lb.add(ib[i]);
		}
		Collections.sort(lb);
		int[] ic = readNums();
		for (int i = 0; i < ic.length; i++) {
			lc.add(ic[i]);
		}
		Collections.sort(lc);
		long ans = 0;
		for (int i = 0; i < la.size(); i++) {
			int p = la.get(i);
			for (int j = 0; j < lb.size(); j++) {
				int q = lb.get(j);
				if (p < q) {
					for (int k = 0; k < lc.size(); k++) {
						int r = lc.get(k);
						if (q < r) {
							ans++;
						}
					}
				}
			}
		}
		pln(ans);
	}

	// -----------------------------------------------------
	// 2018/04/25 r1
	// -----------------------------------------------------
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
			nums[i] = plong(flds[i]);
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
	static boolean _bElapsed = false;

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		_in = new BufferedReader(new InputStreamReader(System.in));
		_out = new PrintWriter(System.out);
		new Main().solve();
		_out.flush();
		long end = System.currentTimeMillis();
		if (_bElapsed)
			System.err.println((end - start) + "ms");
	}
}