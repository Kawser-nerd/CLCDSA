import java.util.*;

public class Main {
	static final long MOD = 1000000007L;
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long total = a * b;
		total %= MOD;
		total *= c;
		total %= MOD;
		System.out.println(total);
	}
}