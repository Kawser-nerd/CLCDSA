import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int K = scanner.nextInt();

		Integer num[] = new Integer[N];
		for (int i = 0; i < N; i++) {
			num[i] = scanner.nextInt();
		}

		Arrays.sort(num, Collections.reverseOrder());

		int sum = 0;
		for (int i = 0; i < K; i++) {
			sum += num[i];
		}


		System.out.println(sum);
	}

}