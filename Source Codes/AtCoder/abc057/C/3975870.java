import java.util.*;
import java.lang.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long a = 1;
		for (long i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				a = i;
			}
		}
		System.out.println(Math.max(String.valueOf(a).length(), String.valueOf(n / a).length()));
	}
}