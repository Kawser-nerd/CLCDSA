import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		int count = 0;
		int button = 1;
		int[] b = new int[n]; // ??????????
		while (true) {
			b[button - 1] = 1;
			button = a[button - 1];
			count++;

			if (button == 2) {
				System.out.println(count);
				break;
			}

			if (b[button - 1] == 1) {
				System.out.println(-1);
				break;
			}
		}



		sc.close();
	}

}