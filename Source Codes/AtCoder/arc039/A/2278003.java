import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		String sa = String.valueOf(a);
		String sb = String.valueOf(b);
		int topa = Integer.parseInt(sa.substring(0, 1));
		int topb = Integer.parseInt(sb.substring(0, 1));
		int seca = Integer.parseInt(String.valueOf(a).substring(1, 2));
		int secb = Integer.parseInt(String.valueOf(b).substring(1, 2));
		int a3 = Integer.parseInt(String.valueOf(a).substring(2, 3));
		int b3 = Integer.parseInt(String.valueOf(b).substring(2, 3));
		long ans = a - b;
		for(int i = 1; i <= 9; i++) {
			ans = Math.max(100*i+a%100-b, ans);
			ans = Math.max(a - 100*i - b % 100, ans);
		}
		for(int i = 0; i <= 9; i++) {
			ans = Math.max(ans, 100*topa+10*i+a3-b);
			ans = Math.max(ans, a - 100*topb - 10 * i - b3);
			ans = Math.max(ans, 100*topa + 10*seca + i - b);
			ans = Math.max(ans, a - 100*topb - 10*secb - i);
		}
		System.out.println(ans);
	}
}