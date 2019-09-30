import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		int t = sc.nextInt();
		int total = s * a + t * b;
		if (s + t >= k) {
			total -= (s + t) * c;
		}
		System.out.println(total);
	}
}