import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		if (A + B +1 <= C ) {
			System.out.println(B + B + A + 1);
		} else {
			System.out.println(B + C);
		}
	}
}