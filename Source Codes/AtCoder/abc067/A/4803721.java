import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int A = sc.nextInt();
		int B = sc.nextInt();

		if (A % 3 == 0) {
			System.out.println("Possible");
		} else if (B % 3 == 0) {
			System.out.println("Possible");
		} else if ((A + B) % 3 == 0) {
			System.out.println("Possible");
		} else {
			System.out.println("Impossible");
		}
	}
}