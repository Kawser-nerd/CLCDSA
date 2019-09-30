import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int prevA = 0;
		int a = 1;
		int prevB = 1;
		int b = 1;
		for (int i = 2; i <= k; i++) {
			int ta = prevA + a;
			int tb = prevB + b;
			prevA = a;
			a = ta;
			prevB = b;
			b = tb;
		}
		System.out.println(a + " " + b);
	}
}