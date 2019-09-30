import java.util.*;

public class Main {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n * 3];
		for (int i = 0; i < n * 3; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		long total = 0;
		for (int i = 0; i < n; i++) {
			total += (long)arr[3 * n - 2 - i * 2];
		}
		System.out.println(total);
	}
}