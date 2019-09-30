import java.util.*;

public class Main {
	static int[][] field;
	static int n;
	static int m;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		field = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				field[i][j] = sc.nextInt();
			}
		}
		if (check(0, 0)) {
			System.out.println("Found");
		} else {
			System.out.println("Nothing");
		}
	}
	
	static boolean check(int val, int level) {
		if (level == n - 1) {
			for (int i = 0; i < m; i++) {
				if ((val ^ field[level][i]) == 0) {
					return true;
				}
			}
		} else {
			for (int i = 0; i < m; i++) {
				boolean ret = check(val ^ field[level][i], level + 1);
				if (ret) {
					return true;
				}
			}
		}
		return false;
	}
}