import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] pn = new int[N + 1];
		for(int i = 0 ; i < N + 1 ; i++) pn[i] = 1;
		int k = 2;
		while(k * k <= N) {
			if(pn[k] == 1) {
				for(int i = k ; i <= N / k ; i++) {
					pn[i * k] = 0;
				}
			}
			k++;
		}
		if(pn[N] == 1) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}