import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		long k = sc.nextLong();
		sc.close();
		System.out.println(k % 2l == 0 ? a - b : b - a);
	}
}