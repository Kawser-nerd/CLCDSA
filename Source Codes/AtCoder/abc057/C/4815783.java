import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		sc.close();

		int s = (int) Math.ceil(Math.sqrt(n));
		for (long i = s; i > 0; i--) {
			if (n % i == 0) {
				long l = n / i;
				System.out.println(String.valueOf(l).length());
				return;
			}
		}
	}
}