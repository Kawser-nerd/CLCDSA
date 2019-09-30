import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long k = sc.nextLong();
		if (k == 0) {
			System.out.println(2000000000000L - a);
			return;
		}
		long idx = 0;
		while (a < 2000000000000L) {
			idx++;
			a += func(k, a);
		}
		System.out.println(idx);
	}
	
	static long func(long k, long t) {
		return 1 + k * t;
	}
}