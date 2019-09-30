import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int[][] arr = new int[3][3];
		int[] A = new int[2];
		int[] B = new int[2];
		Arrays.fill(A, 101);
		Arrays.fill(B, 101);
		String ans = "Yes";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = reader.nextInt();
			}
		}
		A[0] = arr[0][0] - arr[1][0];
		A[1] = arr[1][0] - arr[2][0];
		B[0] = arr[0][0] - arr[0][1];
		B[1] = arr[0][1] - arr[0][2];

		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < 3; j++) {
				if (arr[i-1][j] - A[i-1] != arr[i][j] ||
					arr[i][j-1] - B[j-1] != arr[i][j]) {
					ans = "No";
				}
			}

		}

		System.out.print(ans);
		reader.close();
	}
}