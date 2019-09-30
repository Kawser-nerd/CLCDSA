import java.util.Scanner;

public class Main {

	private static final String TEAM_A = "TAKAHASHI";
	private static final String TEAM_B = "AOKI";
	private static final String DRAW = "DRAW";

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		double d = sc.nextDouble();
		sc.close();

		double perVicA = b / a;
		double perVicB = d / c;

		if (perVicA == perVicB) {
			System.out.println(DRAW);
		} else if (perVicA > perVicB) {
			System.out.println(TEAM_A);
		} else {
			System.out.println(TEAM_B);
		}
	}
}