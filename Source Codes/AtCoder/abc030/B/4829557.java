import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int shortHand = sc.nextInt();
		int longHand = sc.nextInt();
		sc.close();
		aoki(shortHand, longHand);

	}

	public static void aoki(int n, int m) {
		double rad = Math.abs(((n % 12) * 30.0 + m / (2.0)) - m * 6.0);
		rad = rad > 180. ? 360. - rad : rad;
		System.out.println(Math.round(rad * 1000.) / 1000.);
	}
}