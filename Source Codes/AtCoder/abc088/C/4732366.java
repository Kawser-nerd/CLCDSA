import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int[] c = new int[9];
		for (int i = 0; i < 9; i++) {
			c[i] = sc.nextInt();
		}
		sc.close();

		if (c[3] - c[0] == c[4] - c[1] && c[3] - c[0] == c[5] - c[2]
		&& c[6] - c[3] == c[7] - c[4] && c[6] - c[3] == c[8] - c[5]
		&& c[1] - c[0] == c[4] - c[3] && c[1] - c[0] == c[7] - c[6]
		&& c[2] - c[1] == c[5] - c[4] && c[2] - c[1] == c[8] - c[7]) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}