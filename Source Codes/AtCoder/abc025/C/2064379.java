import java.util.Scanner;

public class Main {

	static int[][] b, c;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		b = new int[2][3];
		c = new int[3][2];
		int sum = 0;
		for(int i = 0 ; i < 2 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				b[i][j] = sc.nextInt();
				sum += b[i][j];
			}
		}
		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < 2 ; j++) {
				c[i][j] = sc.nextInt();
				sum += c[i][j];
			}
		}
		int[][] B = new int[3][3];
		int ans = rec(B, 1);
		System.out.println(ans);
		System.out.println(sum - ans);
	}

	public static int rec(int[][] B, int turn) {
		if(turn == 9) {
			int ret = 0;
			for(int i = 0 ; i < 3 ; i++) {
				for(int j = 0 ; j < 3 ; j++) {
					if(B[i][j] == 0) {
						B[i][j] = 1;
						ret = calc(B);
						B[i][j] = 0;
					}
				}
			}
			return ret;
		}
		int max = 0;
		int min = Integer.MAX_VALUE;
		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				if(B[i][j] == 0) {
					B[i][j] = turn % 2 == 1 ? 1 : 2;
					int x = rec(B, turn + 1);
					max = Math.max(max, x);
					min = Math.min(min, x);
					B[i][j] = 0;
				}
			}
		}
		return turn % 2 == 1 ? max : min;
	}

	public static int calc(int[][] B) {
		int ret = 0;
		for(int i = 0 ; i < 2 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				if(B[i][j] == B[i + 1][j]) {
					ret += b[i][j];
				}
			}
		}
		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < 2 ; j++) {
				if(B[i][j] == B[i][j + 1]) {
					ret += c[i][j];
				}
			}
		}
		return ret;
	}

}