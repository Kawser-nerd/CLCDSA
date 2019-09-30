import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x[] = new int[4];
		int y[] = new int[4];

		for (int i = 0; i < 2; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}

		x[2] = y[0] - y[1] + x[1];
		y[2] = -x[0] + x[1] + y[1];

		x[3] = y[1] - y[2] + x[2];
		y[3] = -x[1] + x[2] + y[2];

		System.out.print(x[2] + " " + y[2] + " " + x[3]  + " " + y[3]);
	}
}