import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int score[] = new int[n];
		int ans = 0;

		for(int i=0; i<n; i++) {
			score[i] = sc.nextInt();
			if(score[i] < 80) {
				ans += 80-score[i];
			}
		}
		System.out.println(ans);
	}

}