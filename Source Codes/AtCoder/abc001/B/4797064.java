import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int m;
		Scanner scanner = new Scanner(System.in);

		m = Integer.parseInt(scanner.nextLine());

		if(70000 < m) {
			System.out.println("89");
		} else if (35000 <= m && m <= 70000) {
			System.out.println((m / 1000 - 30) / 5 + 80);
		} else if (6000 <= m && m <= 30000) {
			System.out.println(m / 1000 + 50);
		} else if (100 <= m && m <= 5000) {
			System.out.printf("%02d\n", m / 100);
		} else if (m < 100) {
			System.out.println("00");
		}

		scanner.close();
	}
}