import java.util.*;

public class Main {
	static int[][][] dp;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int prev = -1;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (prev == a) {
				count++;
				prev = -1;
			} else {
				prev = a;
			}
		}
		System.out.println(count);
	}
}