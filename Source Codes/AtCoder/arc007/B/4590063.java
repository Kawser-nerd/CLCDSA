import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner cin = new Scanner(System.in);

		int N = cin.nextInt();
		int M = cin.nextInt();

		int[] cdCase = new int[N+1];

		// cdcase[0] ???????????
		for (int i = 0; i <= N; i++) {
			cdCase[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int target = cin.nextInt();

			for (int j = 0; j <= N; j++) {
				if (cdCase[j] == target) {
					cdCase[j] = cdCase[0];
					cdCase[0] = target;
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			System.out.println(cdCase[i]);
		}
	}

}