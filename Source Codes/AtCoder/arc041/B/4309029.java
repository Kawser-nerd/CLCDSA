import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] field = new int[n][m];
		int[][] before = new int[n][m];
		for (int i = 0; i < n; i++) {
			char[] arr = sc.next().toCharArray();
			for (int j = 0; j < m; j++) {
				field[i][j] = arr[j] - '0';
			}
		}
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				int x = field[i - 1][j];
				before[i][j] = x;
				field[i - 1][j] -= x;
				field[i + 1][j] -= x;
				field[i][j - 1] -= x;
				field[i][j + 1] -= x;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sb.append(before[i][j]);
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}