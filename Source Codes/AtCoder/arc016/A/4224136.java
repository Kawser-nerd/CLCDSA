import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int ans;
		if (m == 1) {
			ans = 2;
		} else {
			ans = 1;
		}
		System.out.println(ans);
	}
}