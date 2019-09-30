import java.util.Scanner;

public class Main {
	int[][] board = new int[3][3];
	int[][] b = new int[2][3];
	int[][] c = new int[3][2];
	int sum = 0;

	public static void main(String[] args) {
		new Main().solve();
	}
	void solve() {
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				b[i][j] = sc.nextInt();
				sum += b[i][j];
			}
		}

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 2; j++) {
				c[i][j] = sc.nextInt();
				sum += c[i][j];
			}
		}

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				board[i][j] = -1;
			}
		}

		int s = dfs(0);
		System.out.println(s);
		System.out.println(sum - s);
	}

	int dfs(int n) {
		if(n >= 9) return score();
		int ret= n%2==0? 0: sum;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(board[i][j] == -1) {
					board[i][j] = n%2;
					ret = n%2==0? Math.max(ret, dfs(n+1)): Math.min(ret, dfs(n+1));
					board[i][j] = -1;
				}
			}
		}
		return ret;
	}

	int score() {
		int s = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(board[i][j] < 0) continue;
				if(i < 2) if(board[i][j] == board[i+1][j]) s += b[i][j];
				if(j < 2) if(board[i][j] == board[i][j+1]) s += c[i][j];
			}
		}
		return s;
	}
}