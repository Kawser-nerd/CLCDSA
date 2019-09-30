import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int i = sc.nextInt();

		if (i < 1200) {
			System.out.println("ABC");
		} else if (i < 2800) {
			System.out.println("ARC");
		} else {
			System.out.println("AGC");
		}
	}
}