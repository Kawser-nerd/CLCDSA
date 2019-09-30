import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long k = sc.nextLong();
		long s = sc.nextLong();
		long t = sc.nextLong();
		System.out.println(a * s + b * t - (s + t) * (s + t >= k ? c : 0));
	}
}