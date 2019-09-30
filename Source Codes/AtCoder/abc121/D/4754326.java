import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		long A = in.nextLong();
		long B = in.nextLong();

		if (A == B) {
			System.out.println(A);
			return;
		}

		long ans;
		if (A % 2 == 0) {
			ans = 1;
			A += 2;
		} else {
			ans = A++;
		}
		if (B % 2 == 0) {
			ans ^= B--;
		}

		for (long n = 0; n < ((A + B) % 4); n += 2) {
			ans ^= 1;
		}

		System.out.println(ans);
	}
}