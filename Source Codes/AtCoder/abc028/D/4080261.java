import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		double n = sc.nextInt();
		double k = sc.nextInt();

		System.out.println((1 + (n - 1) * 3 + (k - 1) * (n - k) * 6) / n / n / n);
	}
}