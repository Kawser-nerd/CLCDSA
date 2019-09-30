import java.util.Scanner;


public class B {

	static Scanner in = new Scanner(System.in);

	double solve() {
		int H = in.nextInt();
		int N = in.nextInt();
		int M = in.nextInt();
		int[][] c = new int[N][M];
		int[][] f = new int[N][M];
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				c[i][j] = in.nextInt();
			}
		}
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				f[i][j] = in.nextInt();
			}
		}
		
		boolean[][] used = new boolean[N][M];
		boolean[][] reached = new boolean[N][M];
		double[][] time = new double[N][M];
		
		reached[0][0] = true;
		double INF = Double.MAX_VALUE;
		
		int[] di = {-1, 1,  0, 0};
		int[] dj = {0,  0, -1, 1};
		
		while (true) {
			double tb = INF;
			int ib = -1;
			int jb = -1;
			for (int i=0; i<N; ++i) {
				for (int j=0; j<M; ++j) {
					if (used[i][j]) continue;
					if (!reached[i][j]) continue;
					double t = time[i][j];
					if (t < tb) {
						tb = t;
						ib = i;
						jb = j;
					}
				}
			}

			used[ib][jb] = true;
			if (ib==N-1 && jb==M-1) {
				return tb;
			}
			int fb = f[ib][jb];
			int cb = c[ib][jb];
			for (int d=0; d<4; ++d) {
				int i = ib + di[d];
				int j = jb + dj[d];
				if (i<0 || i>=N || j<0 || j>=M) continue;
				int cn = c[i][j];
				int fn = f[i][j];
				if (cn < fn+50) continue;
				if (cn < fb+50) continue;
				if (cb < fn+50) continue;
				
				double first = (H-(cn-50))/10.0;
				if (first < 0) first = 0;
				if (first < tb) {
					first = tb;
				}
				if (first > 0) {
					double h = H - first*10.0 - fb;
					if ( h >= 20) {
						first += 1;
					} else {
						first += 10;
					}
				}
				
				if (first < time[i][j] || !reached[i][j]) {
					time[i][j] = first;
					reached[i][j] = true;
				}
			}
		}
		
	}
	
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (int i=1; i<=T; ++i) {
			double ans = new B().solve();
			System.out.println("Case #" + i + ": " + String.format("%.7f", ans).replace(",", "."));
		}

	}

}
