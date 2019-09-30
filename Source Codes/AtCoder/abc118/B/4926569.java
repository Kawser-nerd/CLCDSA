import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			scanner.nextInt();
			scanner.nextLine();
			Set<Integer> commonSet = new HashSet<>();
			IntStream.range(0, n).forEach(i -> {
				int number = scanner.nextInt();
				Set<Integer> set = new HashSet<>();
				IntStream.range(0, number).forEach(j -> set.add(scanner.nextInt()));
				scanner.nextLine();
				if (0 == i) {
					commonSet.addAll(set);
				} else {
					Set<Integer> removeSet = new HashSet<>();
					for (Integer integer : commonSet) {
						if (!set.contains(integer)) {
							removeSet.add(integer);
						}
					}
					commonSet.removeAll(removeSet);
				}
			});
			System.out.println(commonSet.size());
		}
	}
}