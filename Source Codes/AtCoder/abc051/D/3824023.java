import java.util.Scanner;

public class Main {
	static final long INF = (1L << 32);
	static long[][]d;;
	static int N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int M = sc.nextInt();
		d = new long[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i == j) {
					d[i][j] = 0;
				}else {
					d[i][j] = INF;
				}
			}
		}
		Data[] data = new Data[M];
		for(int i = 0; i < M; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			data[i] = new Data(a, b, c);
			d[a][b] = c;
			d[b][a] = c;
		}
		sc.close();
		warshallFloyd();
		int cnt = 0;
		for(int i = 0; i < M; i++) {
			int a = data[i].a;
			int b = data[i].b;
			boolean flag = true;
			loop: for(int j = 0; j < N; j++) {
				for(int k = 0; k < N; k++) {
					long d1 = d[j][a] + data[i].c + d[b][k];
					long d2 = d[j][k];
					if(d1 == d2) {
						flag = false;
						break loop;
					}
				}
			}
			if(flag) cnt++;
		}
		System.out.println(cnt);
//		for(int i = 0; i < N; i++) {
//			for(int j = 0; j < N; j++) {
//				System.out.print(d[i][j] + " ");
//			}
//			System.out.println();
//		}
	}
	static class Data{
		int a, b, c;
		public Data(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
	}
	static void warshallFloyd() {
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                if(d[i][k] == INF) continue;
                for(int j = 0; j < N; j++) {
                    if(d[k][j] == INF) continue;
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}