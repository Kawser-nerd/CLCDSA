import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int x = scanner.nextInt();

		List<Integer> list = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			list.add(scanner.nextInt());
		}

		Collections.sort(list);

		int count = 0;
		for (int i = 0; i < N; i++) {
			x -= list.get(i);
			if (x < 0)
				break;
			else
				count++;
		}

		if (x > 0) count--;

		System.out.println(count);
	}

}