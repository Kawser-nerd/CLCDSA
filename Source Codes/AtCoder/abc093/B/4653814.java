import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int K = reader.nextInt();
		for (int i = A; i <= B; i++) {
			if ((Math.abs(A - i) < K) || (Math.abs(B - i) < K)) {
				System.out.println(i);
			}
		}
		reader.close();
	}
}