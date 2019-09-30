// WA??????

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner scanner = new Scanner(System.in);

		int N = scanner.nextInt();

		List<Long> alist = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			alist.add(scanner.nextLong());
		}

		if (alist.get(0) != 0) {
			System.out.println("-1");
			return;
		}

		long count = 0;

		for(int i = 0; i < N-1; i++) {
			long a_i = alist.get(i);
			long a_i_1 = alist.get(i+1);
			if (a_i_1 == a_i + 1) { // 1, 2
				count = count + 1;
			} else if (a_i_1 - a_i > 1) { // 1, 3
				System.out.println("-1");
				return;
			} else {
				count = count + a_i_1;
			}
		}
		System.out.println(count);
	}
}