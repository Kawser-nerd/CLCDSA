import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> a = new ArrayList<>();
		List<Integer> b = new ArrayList<>();
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (i != j && j != n - i + 1) {
						a.add(i);
						b.add(j);
					}
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (i != j && j != n - i) {
						a.add(i);
						b.add(j);
					}
				}
			}
		}
		System.out.println(a.size());
		for (int i = 0; i < a.size(); i++) {
			System.out.println(a.get(i) + " " + b.get(i));
		}
	}
}