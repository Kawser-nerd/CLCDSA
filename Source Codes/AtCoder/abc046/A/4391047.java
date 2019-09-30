import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();

			int count = 1;
			if (b != a) {
				count++;
			}
			if (c != b && c != a) {
				count++;
			}

			System.out.println(count);

		} finally {
			sc.close();
		}
	}
}