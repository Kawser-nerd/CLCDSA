import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			scanner.nextLine();
			List<Integer> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				list.add(scanner.nextInt());
			}
			scanner.nextLine();
			List<Integer> resultList = new LinkedList<>();
			if (check(list, resultList)) {
				for (int i = resultList.size() - 1; i >= 0; i--) {
					System.out.println(resultList.get(i));
				}
			} else {
				System.out.println(-1);
			}
		}
	}

	private static boolean check(List<Integer> list, List<Integer> resultList) {
		// System.out.println("list=" + toString(list) + ", resultList=" + toString(resultList));
		if (list.isEmpty()) {
			return true;
		}
		for (int i = list.size() - 1; i >= 0; i--) {
			if (list.get(i) == (i + 1)) {
				resultList.add(i + 1);
				list.remove(i);
				if (check(list, resultList)) {
					return true;
				} else {
					return false;
				}
			}
		}
		return false;
	}
}