import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			scanner.nextLine();
			List<Store> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				Store store = new Store();
				store.price = scanner.nextInt();
				store.amount = scanner.nextInt();
				list.add(store);
				scanner.nextLine();
			}
			List<Store> newList = list.stream().sorted((x, y) -> x.price - y.price).collect(Collectors.toList());
			long sum = 0;
			for (int i = 0; i < newList.size(); i++) {
				Store store = newList.get(i);
				if (store.amount >= m) {
					sum += (long) store.price * m;
					break;
				} else {
					sum += (long) store.price * store.amount;
					m -= store.amount;
				}
			}
			System.out.println(sum);
		}
	}

	private static class Store {
		int price;
		int amount;
	}
}