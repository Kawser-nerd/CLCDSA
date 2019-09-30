import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int sum = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (a > 0) {
				sum += a;
				count++;
			}
		}
		int ans = sum / count;
		if (sum % count != 0) {
			ans++;
		}
		System.out.println(ans);
	}
}