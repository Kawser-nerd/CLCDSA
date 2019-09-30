import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();

		ArrayList<Long> list = new ArrayList<>();
		for(int i = 0; i < 3 * N; i++) {
			list.add(scanner.nextLong());
		}

		//????????
		Collections.sort(list, Collections.reverseOrder());

		long sum = 0;
		for(int i = 0; i < N; i++) {
			sum += list.get(1 + (2 * i));
		}

		System.out.println(sum);
	}

}