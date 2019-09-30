import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if (a >= b && a >= c) {
			System.out.println(a * 10 + b + c);
		}
		else if (b >= a && b >= c) {
			System.out.println(b * 10 + a + c);
		}
		else if (c >= b && c >= a) {
			System.out.println(c * 10 + b + a);
		}	
	}
}