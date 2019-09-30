import java.io.PrintStream;
import java.util.Scanner;

public class Main {

	static void exec(Scanner in, PrintStream out) {
		int A = in.nextInt();
		int B = in.nextInt();
		int C = in.nextInt();
		int X = in.nextInt();
		int Y = in.nextInt();
		if (C * 2 < A + B) {
			int price = C * 2 * Math.min(X, Y);
			if (X < Y) {
				if (C * 2 < B) {
					price += C * 2 * (Y - X);
				} else {
					price += B * (Y - X);
				}
			} else if (X > Y) {
				if (C * 2 < A) {
					price += C * 2 * (X - Y);
				} else {
					price += A * (X - Y);
				}
			}
			out.println(price);
		} else {
			out.println(A * X + B * Y);
		}
	}

	public static void main(String[] args) {
		exec(new Scanner(System.in), System.out);
	}

}