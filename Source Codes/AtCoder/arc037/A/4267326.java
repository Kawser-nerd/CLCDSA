import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int m = sc.nextInt();
			sum += Math.max(0, 80 - m);
		}
		System.out.println(sum);
	}
}