import java.util.Scanner;

public class Main {
	static final int MAX = 10;
    static final int INF = 1 << 21;
    static final int WHITE = 0;
    static final int GRAY = 1;
    static final int BLACK = 2;
    static int n = 10;
    static int[][]M;;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int[][] c = new int[10][10];
		int[][] A = new int[H][W];
		for(int i = 0; i < 10; i++) {
			for(int j= 0; j < 10; j++) {
				c[i][j] = sc.nextInt();
			}
		}
		for(int i = 0; i < H; i++) {
			for(int j= 0; j < W; j++) {
				A[i][j] = sc.nextInt();
			}
		}
		sc.close();
		M = c;
		int[] d = new int[10];
		for(int i = 0; i <10; i++) {
			if(i == 1) d[i] = 0;
			else {
				d[i] = dijkstra(i);
			}
		}
		int sum = 0;
		for(int i = 0; i < H; i++) {
			for(int j= 0; j < W; j++) {
				if(A[i][j] != -1 && A[i][j] != 1) {
					sum += d[A[i][j]];
				}
			}
		}
		System.out.println(sum);
	}
	static int dijkstra(int t) {
        int minV;
        int[]d = new int [MAX];
        int[]color = new int [MAX];
        for(int i = 0; i < n; i++) {
            d[i] = INF;
            color[i] = WHITE;
        }
        d[t] = 0;
        color[t] = GRAY;
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
        return d[1];
    }
}