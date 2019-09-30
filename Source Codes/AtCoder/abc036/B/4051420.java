import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[][] field = new char[n][n];
		for (int i = 0; i < n; i++) {
			field[i] = sc.next().toCharArray();
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sb.append(field[n - j - 1][i]);
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}