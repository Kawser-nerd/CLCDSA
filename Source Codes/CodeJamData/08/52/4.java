import java.io.*;
import java.util.*;
import java.text.*;

/**
 * @author Roman Elizarov
 */
public class B extends Thread {
	public static void main(String[] args) throws FileNotFoundException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length == 0)
			args = new String[] { "B.in" };
		for (String infile : args)
			new B().go(infile);
	}

	private Scanner in;
	private PrintWriter out;

	private void go(String infile) throws FileNotFoundException, InterruptedException {
		open(infile);
		start();
		join();
		close();
	}

	private void open(String infile) throws FileNotFoundException {
		String outfile = infile.replaceFirst("(\\.in)?$", ".out");
		System.out.printf("Processing %s, writing %s...%n", infile, outfile);
		in = new Scanner(new File(infile));
		out = new PrintWriter(new File(outfile));
	}

	private void close() {
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}

	public void run() {
		int n = in.nextInt();
		int lastp = 0;
		boolean nl = true;
		long start = System.currentTimeMillis();
		for (int i = 1; i <= n; i++) {
			if (nl) {
				System.out.print(new SimpleDateFormat("HH:mm:ss.SSS").format(new Date()) + " : ");
				nl = false;
			}
			doCase(i);
			System.out.print(".");
			int p = i * 20 / n;
			if (lastp != p) {
				System.out.printf("%d%%, ~%d sec more to go%n", (i * 100 / n), (System.currentTimeMillis() - start) * (n - i) / i / 1000);
				lastp = p;
				nl = true;
			}
		}
	}

	static final int MAX = 15;

	static class Pos {
		int moves;
		int i;
		int j;
		int a;

		public int num() {
			return i | (j << 4) | ((a + 1) << 8);
		}
	}

	static final int[] dx = new int[] { 1, 0, -1, 0 };
	static final int[] dy = new int[] { 0, 1, 0, -1 };

	int r;
	int c;
	boolean[][] w;

	private void doCase(int caseNumber) {
		// read case
		r = in.nextInt();
		c = in.nextInt();
		w = new boolean[r][c];
		char[][] f = new char[r][];
		in.nextLine();
		int sr = -1;
		int sc = -1;
		int cr = -1;
		int cc = -1;
		for (int i = 0; i < r; i++) {
			f[i] = in.nextLine().toCharArray();
			assert f[i].length == c;
			for (int j = 0; j < c; j++) {
				switch (f[i][j]) {
				case 'O':
					sr = i;
					sc = j;
					break;
				case 'X':
					cr = i;
					cc = j;
					break;
				case '#':
					w[i][j] = true;
					break;
				}
			}
		}
		assert sr >= 0 && sc >= 0;
		assert cr >= 0 && cc >= 0;

		// solve case
		LinkedList<Pos> queue = new LinkedList<Pos>();
		HashSet<Integer> inq = new HashSet<Integer>();

		Pos p = new Pos();
		p.i = sr;
		p.j = sc;
		p.a = -1;
		queue.add(p);
		inq.add(p.num());

		while (!queue.isEmpty()) {
			p = queue.remove();
			if (p.i == cr && p.j == cc) {
				out.printf("Case #%d: %d%n", caseNumber, p.moves);
				return;
			}
			for (int s = -1; s < 4; s++) {
				int newa = p.a;
				if (s >= 0) {
					int i = p.i;
					int j = p.j;
					while (ok(i + dx[s], j + dy[s])) {
						i += dx[s];
						j += dy[s];
					}
					newa = portal(i, j);
				}
				for (int m = 0; m < 4; m++) {
					Pos q = new Pos();
					q.moves = p.moves + 1;
					q.i = p.i + dx[m];
					q.j = p.j + dy[m];
					q.a = newa;
					if (ok(q)) {
						if (inq.add(q.num()))
							queue.add(q);
					} else {
						if (newa >= 0) {
							q.i = unpi(newa);
							q.j = unpj(newa);
							if (inq.add(q.num()))
								queue.add(q);
						}
					}
				}
			}
		}

		// write case result
		out.printf("Case #%d: THE CAKE IS A LIE%n", caseNumber);
	}

	private int portal(int i, int j) {
		return i | (j << 4);
	}

	private int unpi(int a) {
		return a & 0xf;
	}

	private int unpj(int a) {
		return a >> 4;
	}

	private boolean ok(Pos q) {
		return ok(q.i, q.j);
	}

	private boolean ok(int i, int j) {
		return i >= 0 && i < r && j >= 0 && j < c && !w[i][j];
	}
}