import java.util.List;
import java.util.Scanner;

public class Main {
	static int n;
	static long[][]M;
	static int[]G;
	static List<Integer> list1;
	static List<Integer> list2;
	static int sx, sy, gx, gy, H, W, ns;
	static long T;
	static long INF;
	static final int WHITE = 0;
	static final int GRAY = 1;
	static final int BLACK = 2;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		H = scan.nextInt();
		W = scan.nextInt();
		T = scan.nextLong();
		n = H * W;
		char[][] s = new char[H][W];
		G = new int[n];
		M = new long[n][n];
		INF = T + 1;
		for(int i = 0; i < H; i++) {
			String t = scan.next();
			for(int j = 0; j < W; j++) {
				char c = t.charAt(j);
				s[i][j] = t.charAt(j);
				if(c == 'S') {
					sx = j;
					sy = i;
				}
				if(c == 'G') {
					gx = j;
					gy = i;
				}
				if(c == '#') {
					int p = W * i + j;
					G[p] = 1;
				}
			}
		}
		scan.close();
		ns = W * sy + sx;
		dijkstra();
		long l = 1;
		long r = T;
		long mid = 0;
		while(r - l > 1) {
			mid = (l + r) / 2;
			initM(mid);
			long t = dijkstra();
			//System.out.println(t);
			if(t > T) {
				r = mid;
			}else {
				l = mid;
			}
		}
		//System.out.println(r);
		System.out.println(l);

	}
	static long dijkstra() {
		long minV;
		long []d = new long[n];
		int[]color = new int[n];
		for(int i = 0; i < n; i++) {
			d[i] = INF;
			color[i] = WHITE;
		}

		d[ns] = 0;
		color[ns] = GRAY;
		while(true) {
			minV = INF;
			int u = -1;
			for(int i = 0; i < n; i++) {
				if(minV > d[i] && color[i] != BLACK) {
					u = i;
					minV = d[i];
				}
			}
			if(u == -1) break;
			color[u] = BLACK;
			for(int v = 0; v < n; v++) {
				if(d[v] > d[u] + M[u][v]) {
					d[v] = d[u] + M[u][v];
					color[v] = GRAY;
				}
			}
		}
		int ng = W * gy + gx;
		return d[ng];
	}
	static void initM(long k) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				M[i][j] = INF;
			}
		}
		int m = H * W - 1;
		int[]di = {-1, 1, W, -W};
		for(int i = 0; i <= m; i++) {
			for(int j = 0; j < 4; j++) {
				int ni = i + di[j];
				if(i % W == 0 && j == 0) {
					continue;
				}
				if(i % W == W - 1 && j == 1) {
					continue;
				}
				if(0 <= ni && ni <= m) {
					if(G[ni] == 1) {
						M[i][ni] = k;
					}else {
						M[i][ni] = 1;
					}
				}
			}
		}
	}
}