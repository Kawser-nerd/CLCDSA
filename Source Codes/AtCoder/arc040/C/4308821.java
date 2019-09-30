import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[][] field = new char[n][n];
		for (int i = 0; i < n; i++) {
			field[i] = sc.next().toCharArray();
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][n - 1 - j] == '.') {
					count++;
					if (i != n - 1) {
						for (int k = n - 1 - j; k < n; k++) {
							field[i + 1][k] = 'o';
						}
					}
					break;
				}
			}
		}
		System.out.println(count);
	}
}