import java.io.*;
import java.util.*;


public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	int s;
	final int OUT = Integer.MAX_VALUE;
	int up;
	String[] name = "bridge-fork-ring".split("[-]");
	int[][] a;
	boolean[][] were;
	int[] cx, cy;
	int[] dx = new int[]{-1, -1, 0, 1, 1, 0};
	int[] dy = new int[]{-1, 0, 1, 1, 0, -1};
	
	private void solve() {
		s = in.nextInt();
		int moves = in.nextInt();
		a = new int[2 * s + 1][2 * s + 1];
		were = new boolean[2 * s + 1][2 * s + 1];
		cx = new int[]{1, 1, s, 2 * s - 1, 2 * s - 1, s};
		cy = new int[]{1, s, 2 * s - 1, 2 * s - 1, s, 1};
		int m;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				if (i >= 1 && j >= 1 && i < 2 * s && j < 2 * s && Math.abs(i - j) < s) {
					a[i][j] = -1;
				} else {
					a[i][j] = OUT;
				}
			}
		}
		m = 0;
		for (int i = 0; i < moves; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			a[x][y] = m++;
		}
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				if (a[i][j] == -1) {
					a[i][j] = m++;
				}
			}
		}
		int[] first = new int[3];
		for (int type = 0; type < 3; type++) {
			int low = 0;
			int high = moves + 1;
			while (low + 1 < high) {
				up = (low + high) / 2;
				boolean present = false;
				switch (type) {
				case 0: present = hasBridge(); break;
				case 1: present = hasFork(); break;
				case 2: present = hasRing(); break;
				}
				if (present) {
					high = up;
				} else {
					low = up;
				}
			}
			first[type] = high;
		}
		m = Math.min(first[0], Math.min(first[1], first[2]));
		if (m == 1) {
			up = 1;
			System.out.println(hasBridge());
		}
		if (m > moves) {
			out.println("none");
			return;
		}
		String s = "";
		for (int type = 0; type < 3; type++) {
			if (first[type] == m) {
				if (!s.isEmpty()) {
					s += '-';
				}
				s += name[type];
			}
		}
		out.println(s + " in move " + m);
	}

	private boolean hasRing() {
		for (int i = 0; i < a.length; i++) {
			Arrays.fill(were[i], false);
		}
		for (int i = 0; i < a.length; i++) {
			jloop:
			for (int j = 0; j < a.length; j++) {
				int aa = a[i][j];
				if (aa == OUT) {
					continue;
				}
				if (aa < up) {
					for (int d = 0; d < 6; d++) {
						int bb = a[i + dx[d]][j + dy[d]];
						if (bb == OUT || bb >= aa) {
							continue jloop;
						}
					}
					return true;
				} else {
					if (were[i][j]) {
						continue;
					}
					outside = false;
					empty = true;
					dfs(i, j);
					if (!outside) {
						return true;
					}
				}
			}
		}
		return false;
	}

	private boolean hasFork() {
		for (int i = 0; i < a.length; i++) {
			Arrays.fill(were[i], false);
		}

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				int aa = a[i][j];
				if (aa == OUT || aa >= up || were[i][j]) {
					continue;
				}
				sides = 0;
				empty = false;
				dfs(i, j);
				if (Integer.bitCount(sides) >= 3) {
					return true;
				}
			}
		}
		return false;
	}

	private boolean hasBridge() {
		for (int i = 0; i < a.length; i++) {
			Arrays.fill(were[i], false);
		}
		for (int c = 0; c < 6; c++) {
			if (a[cx[c]][cy[c]] >= up) {
				continue;
			}
			if (were[cx[c]][cy[c]]) {
				return true;
			}
			empty = false;
			dfs(cx[c], cy[c]);
		}
		return false;
	}
	
	int sides;
	boolean outside;
	boolean empty;
	
	private void dfs(int x, int y) {
		{
			int side = 0;
			if (x == 1) side |= 1;
			if (y == 1) side |= 2;
			if (x == 2 * s - 1) side |= 4;
			if (y == 2 * s - 1) side |= 8;
			if (x - y == s - 1) side |= 16;
			if (y - x == s - 1) side |= 32;
			if (Integer.bitCount(side) == 1) {
				sides |= side;
			}
		}
		were[x][y] = true;
		for (int d = 0; d < 6; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			int aa = a[xx][yy];
			if (aa == OUT) {
				outside = true;
				continue;
			}
			if (were[xx][yy]) {
				continue;
			}
			if (empty) {
				if (aa < up) {
					continue;
				}
			} else {
				if (aa >= up) {
					continue;
				}
			}
			dfs(xx, yy);
		}
	}
	
	static boolean temp = false;

	public static void main(String[] args) throws IOException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			temp = (t == 55);
			Thread thread = new Thread(new Runnable() {
				@Override
				public void run() {
					new B().solve();
				}
			});
			thread.start();
			thread.join();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
