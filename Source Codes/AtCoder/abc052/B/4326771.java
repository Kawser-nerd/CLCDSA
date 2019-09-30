import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int n = sc.nextInt();
		String s = sc.next();
		int x = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == 'I') {
				x++;
			} else if (s.charAt(i) == 'D') {
				x--;
			}
			ans = Math.max(ans, x);
		}
		System.out.println(ans);
	}
}