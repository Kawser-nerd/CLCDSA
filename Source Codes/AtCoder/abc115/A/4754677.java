import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D;
		D = sc.nextInt();
		if (D == 25) {
			System.out.println("Christmas");
		}
		if (D == 24) {
			System.out.println("Christmas Eve");
		}
		if (D == 23) {
			System.out.println("Christmas Eve Eve");
		}
		if (D == 22) {
			System.out.println("Christmas Eve Eve Eve");
		}
		sc.close();
	}

}