import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "A-large";

	int MAX = 3001;

	public void solve() throws Exception {

		int[] dx = new int[] { 1, 0, -1, 0 };
		int[] dy = new int[] { 0, 1, 0, -1 };
		int ntest = iread();
		for (int t = 1; t <= ntest; t++) {
			System.out.println(t);
			int n = iread();
			String[] cmd = new String[n];
			int[] cnt = new int[n];
			for (int i = 0; i < n; i++) {
				cmd[i] = readword();
				cnt[i] = iread();
			}
			int x = MAX, y = MAX;
			int op = 0;
			long S1 = 0;
			int[] miny = new int[2 * MAX], maxy = new int[2 * MAX];
			int[] minx = new int[2 * MAX], maxx = new int[2 * MAX];
			int x1=Integer.MAX_VALUE, y1 = Integer.MAX_VALUE, x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
			Arrays.fill(miny, Integer.MAX_VALUE);
			Arrays.fill(maxy, Integer.MIN_VALUE);
			Arrays.fill(minx, Integer.MAX_VALUE);
			Arrays.fill(maxx, Integer.MIN_VALUE);
			for (int i = 0; i < n; i++)
				for (int k = 0; k < cnt[i]; k++)
					for (int j = 0; j < cmd[i].length(); j++) {
						char c = cmd[i].charAt(j);
						if (c == 'L') {
							op = (op + 1) % 4;
							continue;
						}
						if (c == 'R') {
							op = (op + 3) % 4;
							continue;
						}
						S1 += dy[op] * x;
						if (dx[op] == 1) {
							miny[x] = Math.min(miny[x], y);
							maxy[x] = Math.max(maxy[x], y);
						}
						if (dy[op]==1)
						{
							minx[y] = Math.min(minx[y], x);
							maxx[y] = Math.max(maxx[y], x);
						}
						x += dx[op];
						y += dy[op];
						if (dx[op] == -1) {
							miny[x] = Math.min(miny[x], y);
							maxy[x] = Math.max(maxy[x], y);
						}
						if (dy[op]==-1)
						{
							minx[y] = Math.min(minx[y], x);
							maxx[y] = Math.max(maxx[y], x);
						}
						x1 = Math.min(x1, x);
						y1 = Math.min(y1, y);
						x2 = Math.max(x2, x);
						y2 = Math.max(y2, y);
					}
			S1 = Math.abs(S1);
			long S2 = 0;
			for (int i = x1; i <=x2; i++)
				for (int j=y1; j<=y2; j++)
					if (minx[j] <=i&&i<maxx[j]||
						miny[i] <=j&&j<maxy[i])
						S2++;
			long ans = S2 - S1;
			out.write("Case #" + t + ": " + ans + "\n");
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
