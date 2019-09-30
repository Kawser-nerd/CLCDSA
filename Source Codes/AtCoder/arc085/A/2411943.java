import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
	final int _intMax = Integer.MAX_VALUE; // =2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; // =9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;
	static boolean bElapsed = false;

	void solve() {
		int[] ia = readNums();
		int n = ia[0];
		int m = ia[1];
		int o = n - m;
		double ans = 1900.0 * m + 100.0 * o;
		for (int i = 0; i < m; i++) {
			ans *= 2.0;
		}
		pln((int) ans);
	}

	void solve1() {
		int[] ia = readNums();
		int n = ia[0];
		int m = ia[1];
		int o = n - m;
		double ans = 0;
		double div = 2;
		int cnt = 1;
		while (cnt < 100) {
			double delta = cnt * 1900.0 * m / div;
			ans += delta + 100.0 * o;
			div *= 2.0;
			cnt++;
		}
		pln(ans);
	}

	void solve0() {
		int[] ia = readNums();
		int n = ia[0];
		int m = ia[1];
		int o = n - m;
		int ans = 0;
		int div = 2;
		int cnt = 1;
		while (true) {
			int delta = cnt * 1900 * m / div;
			if (delta < 1)
				break;
			ans += delta + 100 * o;
			div *= 2;
			cnt++;
		}
		pln(ans);
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