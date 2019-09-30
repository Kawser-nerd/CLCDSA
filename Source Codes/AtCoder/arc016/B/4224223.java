import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[][] field = new char[n][9];
		for (int i = 0; i < n; i++) {
			field[i] = sc.next().toCharArray();
		}
		int count = 0;
		for (int i = 0; i < 9; i++) {
			char prev = 'a';
			for (int j = 0; j < n; j++) {
				char c = field[j][i];
				if (c == 'x' || (c == 'o' && prev != 'o')) {
					count++;
				}
				prev = c;
			}
		}
		System.out.println(count);
	}
}