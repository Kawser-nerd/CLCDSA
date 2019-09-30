import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();

		if (a == b) {
			System.out.println(c);
		} else if (a == c) {
			System.out.println(b);
		} else {
			System.out.println(a);
		}
	}
}