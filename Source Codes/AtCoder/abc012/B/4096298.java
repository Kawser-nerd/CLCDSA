import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int s = n % 60;
		n /= 60;
		int m = n % 60;
		int h = n / 60;
		System.out.printf("%02d:%02d:%02d\n", h, m, s);
	}
}