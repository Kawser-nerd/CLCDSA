import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long a = sc.nextInt();
		long b = sc.nextInt();
		long min = Integer.MAX_VALUE;
		long max = 0;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			long s = sc.nextInt();
			if (max < s) {
				max = s;
			}
			if (min > s) {
				min = s;
			}
			sum += s;
		}
		if (max - min == 0) {
			System.out.println(-1);
			return;
		}
		double p = (double) b / (double)(max - min);
		double q = a - (double)sum * p / (double) n;
		System.out.print(p + " " + q);
	}
}