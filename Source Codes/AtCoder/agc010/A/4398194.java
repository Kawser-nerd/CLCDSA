import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		int e = 0;
		int o = 0;
		for(int i = 0; i < N; i++) {
			if(A[i] % 2 == 0) {
				e++;
			}else {
				o++;
			}
		}
		if(o % 2 == 1) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
		}

	}
}