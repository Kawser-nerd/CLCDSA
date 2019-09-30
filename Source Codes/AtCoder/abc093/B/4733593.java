import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A, B, K;
		A = sc.nextInt();
		B = sc.nextInt();
		K = sc.nextInt();

		for (int i = A; i <= B; i++) {
			if (i - A < K || B - i < K) {
				System.out.println(i);
			}
		}
		sc.close();
	}
}