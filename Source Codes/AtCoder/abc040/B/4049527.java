import java.util.*;

public class Main {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int min = Integer.MAX_VALUE;
		for (int i = 1; i * i <= n; i++) {
			int x = n / i;
			int v = Math.abs(x - i) + n - (i * x);
			if (min > v) {
				min = v;
			}
		}
		System.out.println(min);
	}
}