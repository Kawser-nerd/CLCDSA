import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long ans = 0;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if(a < 80) {
				ans += (80 - a);
			}
		}
		System.out.println(ans);
	}
}