import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int[] arr = new int[N];
		int a = 0;
		int b = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = reader.nextInt();
		}
		Arrays.sort(arr);
		for (int i = N-1; i >= 0; i-=2) {
			a += arr[i];
			if (i > 0) {
				b += arr[i-1];
			}
		}


		System.out.print(a-b);
		reader.close();
	}
}