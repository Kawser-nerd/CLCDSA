import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);

		int[] arr = new int[3];
		arr[0] = reader.nextInt();
		arr[1] = reader.nextInt();
		arr[2] = reader.nextInt();
		int K = reader.nextInt();
		int ans = 0;
		Arrays.sort(arr);
		for (int i = 0; i< K; i++) {
			arr[2] *= 2;
		}
		for (int i = 0; i < 3; i++) {
			ans += arr[i];
		}



		System.out.print(ans);
		reader.close();
	}
}