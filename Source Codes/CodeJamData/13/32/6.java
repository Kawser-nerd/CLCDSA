import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			int x = nextInt();
			int y = nextInt();
			out.println("Case #" + test + ": " + solve(x, y));
		}
	}
	
	char[] dirs;
	int[] dx = {-1, 0, 1, 0};
	int[] dy = {0, -1, 0, 1};
	final int LEFT = 0;
	final int DOWN = 1;
	final int RIGHT = 2;
	final int UP = 3;
	
	int cx;
	int cy;
	int length;
	StringBuilder res;

	private void move(int where) {
		res.append(dirs[where]);
		cx += length * dx[where];
		cy += length * dy[where];
		++length;
	}

	private String solve(int x, int y) {
		dirs = "WSEN".toCharArray();
		if (x < 0) {
			char t = dirs[0];
			dirs[0] = dirs[2];
			dirs[2] = t;
			x = -x;
		}
		if (y < 0) {
			char t = dirs[1];
			dirs[1] = dirs[3];
			dirs[3] = t;
			y = -y;
		}
		
		cx = 0;
		cy = 0;
		length = 1;
		res = new StringBuilder();
		while (cx != x) {
			move(LEFT);
			move(RIGHT);			
		}
		while (cy != y) {
			move(DOWN);
			move(UP);			
		}
		return res.toString();
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("B-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
