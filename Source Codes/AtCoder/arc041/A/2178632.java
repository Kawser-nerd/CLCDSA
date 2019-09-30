import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long x = sc.nextLong(), y = sc.nextLong(), k = sc.nextLong();
		long ans = x + k - ((y < k) ? 2*k - 2*y : 0);
		System.out.println(ans);
	}
}