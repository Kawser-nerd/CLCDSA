import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int min = 1001;
		int max = -1;

		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			if (tmp < min) {
				min = tmp;
			}
			if (tmp > max) {
				max = tmp;
			}
		}

		System.out.println(max - min);

		sc.close();
	}

}