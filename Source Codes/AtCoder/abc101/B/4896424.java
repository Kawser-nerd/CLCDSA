import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int tmp = n;
		int sum = 0;
		while ( tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if ( n % sum == 0 ) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}