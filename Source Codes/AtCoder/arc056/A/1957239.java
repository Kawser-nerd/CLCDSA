import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long k = sc.nextInt();
		long l = sc.nextInt();
		long money = 0L;
		money += (k/l)*b;
		k = k % l;
		money += Math.min(a*k, b);
		System.out.println(money);
	}
}