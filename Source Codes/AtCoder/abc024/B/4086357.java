import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t = sc.nextInt();
		int total = 0;
		int prev = 0;
		int end = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (end <= a) {
				total += t;
			} else {
				total += a - prev;
			}
			prev = a;
			end = a + t;
		}
		System.out.println(total);
	}
}