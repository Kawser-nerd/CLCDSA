import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {
	final int _intMax = Integer.MAX_VALUE; // =2147483647>10^9
	final int _intMin = Integer.MIN_VALUE;
	final long _longMax = Long.MAX_VALUE; // =9223372036854775807L>10^18
	final long _longMin = Long.MIN_VALUE;
	static boolean bElapsed = false;

	void solve() {
		List<Point> lr = new ArrayList<>();
		List<Point> lb = new ArrayList<>();
		PointComparator pcr = new PointComparator(1); // for r
		PointComparator pcb = new PointComparator(2); // for b
		int n = readNum();
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lr.add(new Point(ia[0], ia[1]));
		}
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lb.add(new Point(ia[0], ia[1]));
		}
		Collections.sort(lr, pcr);
		Collections.sort(lb, pcb);
		int ans = 0;
		for (int i = 0; i < lb.size(); i++) {
			Point b = lb.get(i);
			for (int j = 0; j < lr.size(); j++) {
				Point r = lr.get(j);
				if (r.x < b.x && r.y < b.y) {
					ans++;
					lr.remove(j);
					break;
				}
			}
		}
		pln(ans);
	}

	class PointComparator implements Comparator<Point> {
		int mode;

		public PointComparator(int mode) {
			this.mode = mode;
		}

		public int compare(Point p1, Point p2) {
			switch (mode) {
			case 1:
				return -1 * Integer.compare(p1.y, p2.y);
			case 2:
				return 1 * Integer.compare(p1.x, p2.x);
			}
			throw new IllegalStateException();
		}
	}

	void solve2() {
		List<Point> lr = new ArrayList<>();
		List<Point> lb = new ArrayList<>();
		PointComparator1 pc = new PointComparator1();
		PointComparator2 pc2 = new PointComparator2();
		int n = readNum();
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lr.add(new Point(ia[0], ia[1]));
		}
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lb.add(new Point(ia[0], ia[1]));
		}
		int ans = dfs2(new ArrayList<>(lr), new ArrayList<>(lb));
		pln(ans);
	}

	int dfs2(List<Point> lr, List<Point> lb) {
		if (lr.size() == 0)
			return 0;
		PointComparator1 pc = new PointComparator1();
		Point r = lr.get(0);
		int max = 0;
		for (int j = 0; j < lb.size(); j++) {
			Point b = lb.get(j);
			if (pc.compare(r, b) >= 0) {
				continue;
			}
			int ans = 0;
			if (pc.compare(r, b) < 0) {
				ans++;
			}
			List<Point> nlr = new ArrayList<>(lr);
			List<Point> nlb = new ArrayList<>(lb);
			nlr.remove(0);
			nlb.remove(j);
			ans += dfs2(nlr, nlb);
			if (max < ans)
				max = ans;
		}
		return max;
	}

	void solve1() {
		List<Point> lr = new ArrayList<>();
		List<Point> lb = new ArrayList<>();
		PointComparator1 pc = new PointComparator1();
		PointComparator2 pc2 = new PointComparator2();
		int n = readNum();
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lr.add(new Point(ia[0], ia[1]));
		}
		for (int i = 0; i < n; i++) {
			int[] ia = readNums();
			lb.add(new Point(ia[0], ia[1]));
		}
		Collections.sort(lr, pc2);
		Collections.sort(lb, pc2);
		int ans = 0;
		for (int i = lb.size() - 1; i >= 0; i--) {
			Point b = lb.get(i);
			for (int j = lr.size() - 1; j >= 0; j--) {
				Point r = lr.get(j);
				if (pc.compare(r, b) < 0) {
					ans++;
					lb.remove(i);
					lr.remove(j);
					break;
				}
			}
		}
		pln(ans);
	}

	class PointComparator1 implements Comparator<Point> {
		public int compare(Point p1, Point p2) {
			if (p1.x == p2.x && p1.y == p2.y) {
				return 0;
			} else if (p1.x < p2.x && p1.y < p2.y) {
				return -1;
			}
			return 1;
		}
	}

	class PointComparator2 implements Comparator<Point> {
		public int compare(Point p1, Point p2) {
			int r1 = p1.x * p1.x + p1.y * p1.y;
			int r2 = p2.x * p2.x + p2.y * p2.y;
			if (r1 == r2)
				return 0;
			else if (r1 < r2)
				return -1;
			return 1;
		}
	}

	class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Point(Point pt) {
			this.x = pt.x;
			this.y = pt.y;
		}

		public boolean equals(Object o) {
			if (o instanceof Point) {
				Point that = (Point) o;
				return (x == that.x) && (y == that.y);
			}
			return false;
		}

		public int hashCode() {
			return x + (y * 31);
		}

		public String toString() {
			return "(" + x + ", " + y + ")";
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
		for (int i = 0; i < flds.length; i++) {
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
			System.err.println((end - start) + "ms");
		}
	}
}