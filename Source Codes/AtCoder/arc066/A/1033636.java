import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	final int _intMax = Integer.MAX_VALUE; //=2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; //=9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;
	static boolean bElapsed = false;

	void solve() {
		int n = readNum();
		int[] a = readNums();
		int m = (int)pow(10, 9) + 7;
		Arrays.sort(a);
		if (n % 2 == 1) {
			if (a[0] != 0) {
				pln("0");
				return;
			}
			int v = 2;
			int ans = 1;
			for (int i=1; i<n; i+=2) {
				if (a[i] != v || a[i+1] != v) {
					pln("0");
					return;
				}
				v += 2;
				ans = ans * 2 % m;
			}
			pln(ans);
		} else {
			int v = 1;
			int ans = 1;
			for (int i=0; i<n; i+=2) {
				if (a[i] != v || a[i+1] != v) {
					pln("0");
					return;
				}
				v += 2;
				ans = ans * 2 % m;
			}
			pln(ans);
		}
	}

	long pow(long n, long p) {
		return (long)Math.pow(n, p);
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