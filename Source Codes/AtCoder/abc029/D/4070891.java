import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		long count = 0;
		for (int i = 0; i < 11; i++) {
			count += (n / pow10(i + 1)) * pow10(i);
			long target = (n % pow10(i + 1)) / pow10(i);
			if (target > 1) {
				count += pow10(i);
			} else if(target == 1) {
				count += n % pow10(i) + 1;
			}
		}
		System.out.println(count);
	}
	
	static long pow10(int n) {
		if (n == 0) {
			return 1;
		} else {
			return 10 * pow10(n - 1);
		}
	}
}