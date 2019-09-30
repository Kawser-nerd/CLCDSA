import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int k = sc.nextInt();
		int ans = x;
		while(y > 0 && k > 0) {
			ans += 1;
			y--;
			k--;
		}
		while(k > 0 && x > 0) {
			ans--;
			x--;
			k--;
		}
		System.out.println(ans);
	}
}