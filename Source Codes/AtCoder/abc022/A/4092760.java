import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int s = sc.nextInt();
		int t = sc.nextInt();
		int w = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			w += sc.nextInt();
			if (w >= s && w <= t) {
				count++;
			}
		}
		System.out.println(count);
	}
}