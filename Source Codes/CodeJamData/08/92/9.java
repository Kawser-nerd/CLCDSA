import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	BufferedReader br;
	PrintWriter pw;

	private void solve() throws Exception {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter("b.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
		}

		br.close();
		pw.close();
	}

	private void runtest() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int x0 = Integer.parseInt(st.nextToken());
		int y0 = Integer.parseInt(st.nextToken());

		boolean[][] r = new boolean[w][h];
		int[] qx = new int[w * h];
		int[] qy = new int[w * h];
		int now = 0;
		int all = 1;
		qx[0] = x0;
		qy[0] = y0;
		r[x0][y0] = true;
		while (now < all) {
			int x = qx[now];
			int y = qy[now];
			now++;
			if (x + x1 >= 0 && x + x1 < w && y + y1 >= 0 && y + y1 < h && !r[x + x1][y + y1]) {
				qx[all] = x + x1;
				qy[all] = y + y1;
				r[x + x1][y + y1] = true;
				all++;
			}
			if (x + x2 >= 0 && x + x2 < w && y + y2 >= 0 && y + y2 < h && !r[x + x2][y + y2]) {
				qx[all] = x + x2;
				qy[all] = y + y2;
				r[x + x2][y + y2] = true;
				all++;
			}
		}

		int res = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (r[i][j]) {
					res++;
				}
			}
		}
		pw.println(res);

	}

}
