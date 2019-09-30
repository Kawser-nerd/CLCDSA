import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int x = sc.nextInt();
		int[] a = new int[N];

		long count = 0;

		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}

		for (int i = 0; i < N - 1; i++) {
			if (x < a[i] + a[i + 1]) {

				if (a[i + 1] >= (a[i + 1] + a[i]) - x) {

					count += a[i + 1] + a[i] - x;
					a[i + 1] = a[i + 1] - ((a[i + 1] + a[i]) - x);

				} else {
					count+= a[i + 1];
					count +=  Math.abs( a[i + 1] - ((a[i + 1] + a[i]) - x));

					a[i + 1] = 0;
					a[i] = a[i] - Math.abs( a[i + 1] - ((a[i + 1] + a[i]) - x));


				}

			}
		}






		System.out.println(count);


		sc.close();
	}


}