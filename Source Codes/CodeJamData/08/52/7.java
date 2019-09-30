import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "B-large";

	int[] dx = new int[] { 1, 0, -1, 0 };

	int[] dy = new int[] { 0, 1, 0, -1 };

	boolean[][] map;

	int n, m;

	int u, v;

	position[] q;

	int qlen;

	int fx, fy;

	boolean[] was;

	boolean valid(int x, int y) {
		return !(x < 0 || y < 0 || x >= n || y >= m || map[x][y]);
	}

	void portal(int x, int y, int op) {
		while (valid(x + dx[op], y + dy[op])) {
			x += dx[op];
			y += dy[op];
		}
		u=x;v=y;
	}

	int hash(int x, int y, int qx, int qy, int px, int py) {
		return x + (y << 4) + (px << 8) + (qx << 12) + (py << 16) + (py << 20);
	}

	boolean Check(int x, int y, int qx, int qy, int px, int py, int t) {
		if (px < qx || px == qx && py < qy) {
			int z = px;
			px = qx;
			qx = z;
			z = py;
			py = qy;
			qy = z;
		}
		int h = hash(x, y, qx, qy, px, py);
		if (was[h])
			return false;
		was[h] = true;
		q[qlen++] = new position(x, y, qx, qy, px, py, t);
		return (x == fx && y == fy);
	}

	public void solve() throws Exception {
		int ntest = iread();
		main: for (int t = 1; t <= ntest; t++) {
			n = iread();
			m = iread();
			map = new boolean[n][m];
			was = new boolean[1 << 24];
			int sx = 0, sy = 0;
			fx = 0;
			fy = 0;
			for (int i = 0; i < n; i++) {
				String s = readword();
				for (int j = 0; j < m; j++) {
					char d = (s.charAt(j));
					if (d == '#')
						map[i][j] = true;
					if (d == 'O') {
						sx = i;
						sy = j;
					}
					if (d == 'X') {
						fx = i;
						fy = j;
					}
				}
			}
			q = new position[1 << 20];
			qlen = 0;
			portal(sx, sy, 0);
			int u1 = u, v1 = v;
			portal(sx, sy, 1);
			Check(sx, sy, u, v, u1, v1, 0);
			int qcur = 0;
			out.write("Case #" + t + ": ");
			while (qcur < qlen) {
				position c = q[qcur++];
				if (c.x == fx && c.y == fy) {
					out.write(c.t + "\n");
					continue main;
				}
				position p;
				for (int temp = 0; temp < 2; temp++) {
					if (c.x == c.px && c.y == c.py)
						Check(c.qx, c.qy, c.qx, c.qy, c.px, c.py, c.t + 1);
					c.swap();
				}
				for (int j = 0; j < 4; j++) {
					portal(c.x, c.y, j);
					u1=u;v1=v;
					for (int temp = 0; temp < 2; temp++) {
						if (c.x == u && c.y == v)
							Check(c.px, c.py, u, v, c.px, c.py, c.t + 1);
						if (c.x == c.px && c.y == c.py)
							Check(u, v, u, v, c.px, c.py, c.t + 1);
						c.swap();
					}
					for (int k = 0; k < 4; k++) {
						portal(c.x, c.y, k);
						if (c.x == u && c.y == v)
							Check(u1, v1, u, v, u1, v1, c.t + 1);
					}
				}
				for (int k = 0; k < 4; k++) {
					int x1 = c.x + dx[k], y1 = c.y + dy[k];
					if (!valid(x1, y1))
						continue;
					Check(x1, y1, c.qx, c.qy, c.px, c.py, c.t + 1);
				}
			}
			out.write("THE CAKE IS A LIE\n");
		}
	}

	class position {
		int x, y;

		int px, py, qx, qy;

		int t;

		public int hashCode() {
			return hash(x, y, px, py, qx, qy);
		}

		public position(int x, int y, int px, int py, int qx, int qy, int t) {
			this.x = x;
			this.y = y;
			this.px = px;
			this.py = py;
			this.qx = qx;
			this.qy = qy;
			this.t = t;
		}

		void swap() {
			int z = px;
			px = qx;
			qx = z;
			z = py;
			py = qy;
			qy = z;
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}
