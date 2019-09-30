import java.io.*;
import java.util.*;

public class B implements Runnable {
	private MyScanner in;
	private PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int w = in.nextInt();
		int h = in.nextInt();
		Student[] st = new Student[n];
		for (int i = 0; i < n; ++i) {
			st[i] = new Student(i, in.nextInt());
		}
		Arrays.sort(st);
		TreeSet<Circle> more = new TreeSet<Circle>();
		Circle comp = new Circle(-1, -1, -1, -1);
		int curId = 0;
		int centerY = 0;
		final int INF = Integer.MIN_VALUE / 2;
		int lastX = INF;
		int maxR = -1;
		double[] x = new double[n], y = new double[n];
		for (Student s : st) {
			comp.r = s.r;
			Circle fit = more.ceiling(comp);
			if (fit != null) {
				more.remove(fit);
				x[s.id] = fit.x;
				y[s.id] = fit.y;
				continue;
			}
			if (lastX + s.r <= w) {
				lastX = Math.max(lastX + 2 * s.r, s.r);
				maxR = Math.max(maxR, s.r);
				if (maxR - s.r >= 2) {
					int newr = (maxR - s.r) / 2;
					if (centerY - s.r - newr >= 0) {
						more.add(new Circle(lastX - s.r, centerY - s.r - newr, newr,
								curId++));
					}
					if (centerY + s.r + newr <= h) {
						more.add(new Circle(lastX - s.r, centerY + s.r + newr, newr,
								curId++));
					}
				}
			} else {
				more.add(new Circle(w, centerY, Math.min(w - lastX, maxR),
						curId++));
				centerY += maxR + s.r;
				maxR = s.r;
				lastX = s.r;
			}
			x[s.id] = lastX - s.r;
			y[s.id] = centerY;
		}
		if (centerY > h) {
			System.err.println("panic!");
		}
		for (int i = 0; i < n; ++i) {
			out.printf("%.3f %.3f ", x[i], y[i]);
		}
		out.println();
	}

	@Override
	public void run() {
		in = new MyScanner();
		try {
			out = new PrintWriter(new File("B-large.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int tests = in.nextInt();
		for (int i = 0; i < tests; ++i) {
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		in.close();
		out.close();
	}

	public static void main(String[] args) {
		new B().run();
	}

	class Student implements Comparable<Student> {
		public int id, r;

		public Student(int id, int r) {
			this.id = id;
			this.r = r;
		}

		@Override
		public int compareTo(Student o) {
			return o.r - r;
		}
	}

	class Circle implements Comparable<Circle> {
		double x, y;
		int r, id;

		public Circle(double x, double y, int r, int id) {
			this.x = x;
			this.y = y;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Circle o) {
			if (r != o.r) {
				return r - o.r;
			}
			return id - o.id;
		}
	}

	class MyScanner {
		private BufferedReader br;
		private StringTokenizer st;

		public MyScanner() {
			try {
				br = new BufferedReader(new FileReader("B-large.in"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return false;
				}
			}
			return st != null && st.hasMoreTokens();
		}

		private String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return null;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
					return null;
				}
			}
			return st.nextToken();
		}

		public String nextLine() {
			try {
				st = null;
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}