import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		String s = sc.next();
		System.out.println(s.replaceAll(",", " "));

	}
}