import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int N = sc.nextInt();
		char[] map = S.toCharArray();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				N--;
				if (N == 0) {
					System.out.println(map[i] + "" + map[j]);
					return;
				}
			}
		}
	}
}