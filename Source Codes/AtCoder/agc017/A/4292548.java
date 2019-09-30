import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int P = sc.nextInt();
		
		int ki = 0;
		int gu = 0;
		for (int i = 0; i < N; i++) {
			int num = sc.nextInt();
			if (num % 2 == 0) {
				gu++;
			} else {
				ki++;
			}
		}
		
		if (ki == 0) {
			System.out.println(P == 0 ? 1L << N: 0);
		} else {
			System.out.println(1L << N-1);
		}
	}
}