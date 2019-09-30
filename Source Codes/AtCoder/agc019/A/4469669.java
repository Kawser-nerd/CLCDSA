import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long Q = sc.nextInt();
		long H = sc.nextInt();
		long S = sc.nextInt();
		long D = sc.nextInt();
		long N = sc.nextInt();
		sc.close();
		long a = Math.min(4 * Q, Math.min(2 * H, S));
		long ans = Math.min((N / 2) * D + (N % 2) * a, a * N);
		System.out.println(ans);
	}
}