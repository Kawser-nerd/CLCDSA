import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] arr = new String[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.next();
		}
		Arrays.sort(arr);
		int count = 0;
		int max = 0;
		String name = "";
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				count = 1;
				continue;
			}
			if (arr[i].equals(arr[i - 1])) {
				count++;
			} else {
				if (max < count) {
					name = arr[i - 1];
					max = count;
				}
				count = 1;
			}
		}
		if (max < count) {
			name = arr[n - 1];
			max = count;
		}
		System.out.println(name);
	}
}