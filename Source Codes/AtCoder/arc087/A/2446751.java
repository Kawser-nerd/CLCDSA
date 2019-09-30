import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> list = new ArrayList<>();
		int num = scanner.nextInt();
		for (int i = 0; i < num; i++) {
			list.add(scanner.nextInt());
		}
		scanner.close();

		Collections.sort(list);
		int stock = 0;
		int count = 0;
		int stockNum = 0;
		for (int i : list) {
			if (stock != i) {
				stock = i;
				count = i;
			}
			count--;
			if (count == 0) {
				stockNum += stock;
			}
		}
		System.out.println(list.size() - stockNum);
	}
}