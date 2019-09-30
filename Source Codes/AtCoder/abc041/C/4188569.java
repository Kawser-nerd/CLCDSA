import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<KeySort> list = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			list.add(new KeySort(i + 1, sc.nextInt()));
		}
		Collections.sort(list, new KeySortComparator());
		for (int i = 0; i < n; i++) {
			System.out.println(list.get(n - 1 - i).key);
		}
	}
}

class KeySort {
	public int key;
	public long sort;
	public KeySort(int key, long sort) {
		this.key = key;
		this.sort = sort;
	}
}

class KeySortComparator implements Comparator<KeySort> {
	@Override
	public int compare(KeySort sort1, KeySort sort2) {
		return (int) (sort1.sort - sort2.sort);
	}
}