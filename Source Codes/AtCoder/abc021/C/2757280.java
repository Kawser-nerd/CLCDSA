import java.util.Scanner;

public class Main{
	static int N;
//	static int x[];
//	static int y[];
	static int a;
	static int b;
	static int q = 1000000007;


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		a = scan.nextInt() - 1;
		b = scan.nextInt() - 1;
		int M = scan.nextInt();
//		x = new int[M];
//		y = new int[M];

		int [][]A = new int[N][N];
		int [][] B = new int[N][N];
		for(int i = 0; i < M; i++) {
			int x = scan.nextInt() - 1;
			int y = scan.nextInt() - 1;
			A[x][y] = 1;
			A[y][x] = 1;
			B[x][y] = 1;
			B[y][x] = 1;
		}
		scan.close();

		int [][] C = new int[N][N];
		for(int l = 0; l < N; l++) {
			if(B[a][b] != 0) {
				System.out.println(B[a][b]);
				System.exit(0);
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					int t = 0;
					for(int k = 0; k < N; k++) {
						t += B[i][k] * A[k][j];
					}
					t = t % q;
					C[i][j] = t;
				}
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					B[i][j] = C[i][j];
				}
			}
		}
	}
}