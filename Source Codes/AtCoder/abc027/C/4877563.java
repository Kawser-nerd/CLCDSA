import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		sc.close();

		long a = 0;
		int p = 0;
		for (int i = 1; i < 64; i++) {
			a = (long) Math.pow(2, i);
			if (a > n) {
				p = i;
				break;
			}
		}

		a = 1;
		if (p % 2 == 1) {
			for (int i = 1; i < 32; i++) {
				a = 2 * a + 1;
				if (a > n) {
					System.out.println("Aoki");
					return;
				}
				a = 2 * a;
				if (a > n) {
					System.out.println("Takahashi");
					return;
				}
			}
		} else {
			for (int i = 1; i < 32; i++) {
				a = 2 * a;
				if (a > n) {
					System.out.println("Aoki");
					return;
				}
				a = 2 * a + 1;
				if (a > n) {
					System.out.println("Takahashi");
					return;
				}
			}
		}
	}
}