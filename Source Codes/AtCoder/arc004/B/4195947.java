import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int max = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int d = sc.nextInt();
			if (max < d) {
				max = d;
			}
			sum += d;
		}
		System.out.println(sum);
		int rest = sum - max;
		if (rest >= max) {
			System.out.println(0);
		} else {
			System.out.println(max - rest);
		}
	}
}