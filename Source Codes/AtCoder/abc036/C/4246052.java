import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			set.add(a[i]);
		}
		Map<Integer, Integer> map = new TreeMap<>();
		int size = set.size();
		for (int i = 0; i < size; i++) {
			map.put(set.first(), i);
			set.remove(set.first());
		}
		for (int i = 0; i < n; i++) {
			System.out.println(map.get(a[i]));
		}
	}
}