import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		sc.close();
		if(a <= 0 && b >= 0) {
			System.out.println("Zero");
		}else if(b < 0) {
			long l = Math.abs(b - a);
			if(l % 2 == 1) {
				System.out.println("Positive");
			}else {
				System.out.println("Negative");
			}
		}else {
			System.out.println("Positive");
		}
	}
}