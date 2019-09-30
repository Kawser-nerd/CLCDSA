import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int[] nArr = (int[])arr.clone();
		Arrays.sort(nArr);
		HashSet<Integer> setEven = new HashSet<>();
		for (int i = 0; i < n; i += 2) {
			setEven.add(nArr[i]);
		}
		int count = 0;
		for (int i = 1; i < n; i += 2) {
			if (setEven.contains(arr[i])) {
				count++;
			}
		}
		System.out.println(count);
	}
}