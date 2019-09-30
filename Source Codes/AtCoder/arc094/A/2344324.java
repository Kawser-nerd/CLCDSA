import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] tokens = in.nextLine().split(" ");
		List<Integer> values = new ArrayList<>();
		for (String token : tokens) {
			values.add(Integer.parseInt(token));
		}
		Collections.sort(values);
		int result = 0;
		while (true) {
			int r = operation(values);
			if (r == 0) {
				break;
			}
			result += r;
			Collections.sort(values);
		}
		System.out.println(result);
		in.close();
	}

	public static int operation(List<Integer> values) {
		if (values.get(0) == values.get(2)) {
			return 0;
		}
		if (values.get(0) == values.get(1)) {
			int result = values.get(2)-values.get(1);
			values.set(0, values.get(2));
			values.set(1, values.get(2));
			return result;
		}
		if ((values.get(1) - values.get(0)) % 2 == 0) {
			int result = (values.get(1) - values.get(0)) / 2;
			values.set(0, values.get(1));
			return result;
		} else {
			int result = (values.get(1) + 1 - values.get(0)) / 2;
			values.set(0, values.get(1));
			values.set(1, values.get(1) + 1);
			return result;
		}
	}
}