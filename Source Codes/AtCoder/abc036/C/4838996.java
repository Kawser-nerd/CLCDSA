import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			map.put(a[i], 0);
		}
		sc.close();

		int cnt = 0;
		for (int key : map.keySet()) {
			map.put(key, cnt);
			cnt++;
		}

		for (int i = 0; i < n; i++) {
			System.out.println(map.get(a[i]));
		}
	}
}