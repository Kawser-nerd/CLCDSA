import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int sum = 0;
		int x = n;
		while (x > 0) {
			sum += x % 10;
			x /= 10;
		}
		if ((n % 2 != 0 && n % 10 != 5 && sum % 3 != 0 && n != 1) || n == 3 || n == 5 || n == 2) {
			System.out.println("Prime");
		} else {
			System.out.println("Not Prime");
		}
	}
}