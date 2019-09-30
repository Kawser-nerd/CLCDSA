import java.util.Scanner;

public class Main {
	static int N, M, K;
	static int[][] board;
	static int[][][] hisigata;
	static int sum = 0;

	public static void main(String[] args) {
		scan();
		for(int i = 0;i < N;i++) {
			for(int j = 0; j < M;j++){
				if(board[i][j] == 0) search(i,j,K);
			}
		}
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < M;j++) {
				sum += hisigata[i][j][0];
			}
		}

		System.out.println(sum);

	}

	public static void scan() {
		Scanner scan = new Scanner(System.in);

		N = scan.nextInt();
		M = scan.nextInt();
		K = scan.nextInt();
		K--;
		board = new int[N][M];
		hisigata = new int[N][M][2];

		for(int i = 0;i < N;i++) {
			for(int j = 0;j < M;j++) {
				hisigata[i][j][0] = 0;
				hisigata[i][j][1] = 0;
			}
		}

		for(int i = K;i < N - K;i++) {
			for(int j = K;j < M - K;j++) {
				hisigata[i][j][0] = 1;
				hisigata[i][j][1] = -1;
			}
		}

		for(int i = 0;i < N;i++) {
			String S = scan.next();
			for(int j = 0;j < M;j++) {
				board[i][j] = (S.charAt(j) == 'o') ? 1 : 0;
			}
		}

		scan.close();
	}

	public static void search(int x,int y,int depth) {
		if(hisigata[x][y][1] > depth) {
			return;
		}
		else {
			for(int i = -depth;i <= depth;i++) {
				if(kyoukaicheck(x,y + i) && hisigata[x][y + i][1] < depth) {
					hisigata[x][y+i][0] = 0;
					hisigata[x][y+i][1] = depth - abs(i);
				}
			}
			if(kyoukaicheck(x + 1,y)) {
				search(x + 1,y,depth - 1);
			}
			if(kyoukaicheck(x - 1,y)) {
				search(x - 1,y,depth - 1);
			}
		}
	}

	public static boolean kyoukaicheck(int x,int y) {
		if((x >= N || x < 0) || (y >= M || y < 0)) return false;
		else return true;
	}

	public static int abs(int x) {
		return x > 0 ? x : -x;
	}
}