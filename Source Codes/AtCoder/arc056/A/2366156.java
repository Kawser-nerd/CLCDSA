import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = Integer.parseInt(sc.next());
		long b = Integer.parseInt(sc.next());
		long k = Integer.parseInt(sc.next());
		long l = Integer.parseInt(sc.next());
		System.out.println(Math.min(k / l * b + k % l * a, (k + l - 1) / l * b));
	}
}