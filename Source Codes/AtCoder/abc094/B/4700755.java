import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] math = new int[N + 1];
		for (int i = 0; i < M; i++) {
			int x = sc.nextInt();
			math[x]++;
		}
		int route1 = 0;
		int route2 = 0;
		for (int i = (X + 1); i <= N; i++) {
			route1 += math[i];
		}
		for (int i = (X - 1); i >= 0; i--) {
			route2 += math[i];
		}

		if (route1 <= route2) {
			System.out.println(route1);
		} else {
			System.out.println(route2);
		}

		sc.close();

	}

}