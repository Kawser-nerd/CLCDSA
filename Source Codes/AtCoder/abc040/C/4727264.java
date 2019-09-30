import java.util.Scanner;

public class Main {
	static int N;
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		N = reader.nextInt();
		int[] arr = new int[N];
		int[] gaps = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = reader.nextInt();
			if (i > 0) {
				int r = Math.abs(arr[i] - arr[i-1])  + gaps[i-1];
				if(i > 1) {
					r = Math.min(r, Math.abs(arr[i] - arr[i-2]) + gaps[i-2]);
				}
				gaps[i] = r;
			}
		}
		System.out.println(gaps[N-1]);
		reader.close();
	}
}