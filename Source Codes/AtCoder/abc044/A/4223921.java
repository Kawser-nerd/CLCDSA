import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long k = sc.nextLong();
		long x = sc.nextLong();
		long y = sc.nextLong();
		System.out.println(Math.min(n, k) * x + Math.max(n - k, 0) * y);
	}
}