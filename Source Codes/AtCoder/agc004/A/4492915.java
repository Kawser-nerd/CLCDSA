import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		sc.close();
		if(A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
			System.out.println(0);
		}else {
			System.out.println(Math.min(A * B, Math.min(B * C, C * A)));
		}
	}
}