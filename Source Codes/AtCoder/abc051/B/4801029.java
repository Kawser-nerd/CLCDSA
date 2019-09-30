import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int K = sc.nextInt();
		int S = sc.nextInt();

		int count = 0;

		for (int x = 0; x <= K; x++) {
			for (int y = 0; y <= K; y++) {
				if (S - x - y <= K && S >= x + y) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}