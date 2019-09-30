import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long ans = 0;
		for(int i = n; i >= 1; i--) {
			ans += i;
		}
		System.out.println(ans);
	}
}