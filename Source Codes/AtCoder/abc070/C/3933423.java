import java.util.*;

public class Main {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long target = sc.nextLong();
		for (int i = 1; i < n; i++) {
			target = get(target, sc.nextLong());
		}
		System.out.println(target);
	}
	
	static long get(long a, long b){
		return a / gcd(a, b) * b;
	}
	
	static long gcd(long a, long b) {
		long x = a % b;
		if (x == 0) {
			return b;
		} else {
			return gcd(b, x);
		}
	}
}