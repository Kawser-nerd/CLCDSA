import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int C = reader.nextInt();
		int X = reader.nextInt();
		int ans = 0;
		for (int i = 0; i <= A; i++) {
			for (int j = 0; j <= B; j++) {
				for (int k = 0; k <= C; k++) {
					int tmp = i * 500 + j * 100 + k * 50;
					if (tmp == X) {
						ans++;
					}
				}
			}
		}


		System.out.print(ans);
		reader.close();
	}
}