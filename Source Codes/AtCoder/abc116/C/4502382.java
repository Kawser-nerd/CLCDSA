import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int ans = 0;
		int[] h = new int[N];
		int max = 0;
		int height = 0;
		for (int i = 0; i < N; i++) {
			h[i] = reader.nextInt();
			if (h[i] > max) {
				max = h[i];
			}
		}
		while (height < max) {
			for (int i = 0; i < N; i++) {
				if (h[i] > height) {
					ans++;
					if (i < N-1 && h[i+1] > height) {
						ans--;
					}
				}
			}
			height++;
		}
		System.out.print(ans);
		reader.close();

	}

}