import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 1;

	static class Ship {
		int x0, y0, z0;
		int vx, vy, vz;

		public Ship(int x0, int y0, int z0, int vx, int vy, int vz) {
			this.x0 = x0;
			this.y0 = y0;
			this.z0 = z0;
			this.vx = vx;
			this.vy = vy;
			this.vz = vz;
		}
	}

	static final double INF_TIME = 1e20;

	int sqr(int x) {
		return x * x;
	}

	double[] findTime(Ship a, Ship b, double maxDistSq) {

		int dist = sqr(a.x0 - b.x0) + sqr(a.y0 - b.y0) + sqr(a.z0 - b.z0);

		if (a.vx == b.vx && a.vy == b.vy && a.vz == b.vz) {
			if (dist <= maxDistSq) {
				return new double[] { 0, INF_TIME };
			} else {
				return null;
			}
		}

		double A = sqr(a.vx - b.vx) + sqr(a.vy - b.vy) + sqr(a.vz - b.vz);
		double B = (a.vx - b.vx) * (a.x0 - b.x0) + (a.vy - b.vy)
				* (a.y0 - b.y0) + (a.vz - b.vz) * (a.z0 - b.z0);
		B *= 2;
		double C = dist - maxDistSq;

		// A t^2 + B t + C <= 0

		double D = B * B - 4 * A * C;
		if (D < 0) {
			return null;
		}

		double sqD = Math.sqrt(D);
		double from = 0.5 * (-B - sqD) / A;
		double to = 0.5 * (-B + sqD) / A;

		if (to < 0) {
			return null;
		}

		return new double[] { Math.max(from, 0), to };
	}

	static class Event implements Comparable<Event> {
		int from, to;
		double time;
		boolean start;

		int fromIdx;
		Event rev;

		public Event(int from, int to, double time, boolean start) {
			this.from = from;
			this.to = to;
			this.time = time;
			this.start = start;
		}

		@Override
		public int compareTo(Event o) {
			if (time != o.time) {
				return time < o.time ? -1 : 1;
			}
			if (start != o.start) {
				return start ? -1 : 1;
			}
			return 0;
		}
	}

	boolean can(int n, int s, Ship[] a, double maxDistSq) {

		ArrayDeque<Integer> q = new ArrayDeque<>();

		boolean[] vis = new boolean[n];
		
		q.add(0);

		while (!q.isEmpty()) {
			int v = q.poll();
			if (v == 1) {
				return true;
			}
			
			for (int i = 0; i < n; i++) {
				int distSq = sqr(a[v].x0 - a[i].x0) + sqr(a[v].y0 - a[i].y0) + sqr(a[v].z0 - a[i].z0);
				if (distSq <= maxDistSq && !vis[i]) {
					vis[i] = true;
					q.add(i);
				}
			}
		}

		return false;

	}

	void solve() throws IOException {
		int n = nextInt();
		int s = nextInt();

		Ship[] a = new Ship[n];
		for (int i = 0; i < n; i++) {
			int x0 = nextInt();
			int y0 = nextInt();
			int z0 = nextInt();

			int vx = nextInt();
			int vy = nextInt();
			int vz = nextInt();

			a[i] = new Ship(x0, y0, z0, vx, vy, vz);
		}

		double low = 0;
		double high = 4e9;

//		can(n, s, a, 16.1);

		for (int it = 0; it < 60; it++) {
			double mid = (low + high) * 0.5;
			if (can(n, s, a, mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}

		double ans = (low + high) * 0.5;
		ans = Math.max(ans, 0);
		out.println(Math.sqrt(ans));
	}

	C() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("C-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("C-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}