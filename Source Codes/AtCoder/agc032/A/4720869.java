import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();
		ArrayList<Integer> b = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			b.add(a[n - i - 1]);
		}
		int[] ans = new int[n];
		boolean canans = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.size(); j++) {
				if (b.get(j) == b.size() - j) {
					ans[i] = b.get(j);
					b.remove(j);
					break;
				} else if (j == b.size() - 1) {
					i = n;
					System.out.println("-1");
					canans = false;
				}
			}
		}
		if (canans) {
			for (int i = 0; i < n; i++) {
				System.out.println(ans[n - i - 1]);
			}
		}
	}
}