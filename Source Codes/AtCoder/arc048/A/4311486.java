import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int ans = b - a;
		if (a < 0 && b > 0) {
			ans--;
		}
		System.out.println(ans);
	}
}