import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextInt();
		long A = sc.nextInt();
		long B = sc.nextInt();
		sc.close();
		if(N == 1) {
			if(A != B) {
				System.out.println(0);
			}else {
				System.out.println(1);
			}
			System.exit(0);
		}
		if(B < A) {
			System.out.println(0);
			System.exit(0);
		}
		long min = A + B + A * (N - 2);
		long max = A + B + B * (N - 2);
		System.out.println(max - min + 1);
	}
}