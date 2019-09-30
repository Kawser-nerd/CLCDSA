import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// ??????????N??????
		int N = sc.nextInt();
		// ????Y?????????????????1000????
		int Y = sc.nextInt() / 1000;
		/*
		 * 10,000?????a 5,000?????b????? 1,000?????N-a-b??????? Y = N + 10000a + 5000b +
		 * 1000 (N - a - b)????
		 */
		int yukichi = -1;
		int higuchi = -1;
		int noguchi = -1;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N - i; j++) {
				if (Y == N + 9 * i + 4 * j) {
					yukichi = i;
					higuchi = j;
					noguchi = N - yukichi - higuchi;
					break;
				}
			}
		}
		System.out.println(yukichi + " " + higuchi + " " + noguchi);

		sc.close();
	}
}