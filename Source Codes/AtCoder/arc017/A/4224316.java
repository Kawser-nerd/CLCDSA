import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (isPrime(n)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
	
	static boolean isPrime(int x) {
		for (int i = 2; i <= 1000 && i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
}