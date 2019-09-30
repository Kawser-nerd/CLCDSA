import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> b = new ArrayList<Integer>(n);
		for (int i = 0; i < n; i++) {
			b.add(sc.nextInt());
		}
		sc.close();

		List<Integer> ans = new ArrayList<Integer>(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (b.get(j) == j + 1) {
					ans.add(j + 1);
					b.remove(j);
					break;
				}
			}
		}

		if (ans.size() == n) {
			for (int i = n - 1; i >= 0; i--) {
				System.out.println(ans.get(i));
			}
		} else {
			System.out.println(-1);
		}
	}

}