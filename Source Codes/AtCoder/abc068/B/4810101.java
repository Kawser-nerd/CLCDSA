import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int N = sc.nextInt();
		int d = 0;
		if (N == 0) {
			System.out.println("0");
			return;
		}

		for (int i = 0; i < 7; i++) {
			d = (int) Math.pow(2, i);
			if (N / d == 1) {
				break;
			}
		}
		System.out.println(d);
	}
}