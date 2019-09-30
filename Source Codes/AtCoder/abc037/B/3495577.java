import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int[][] q = new int[Q][3];
		for(int i = 0;i < Q;++i) {
			q[i][0] = sc.nextInt();
			q[i][1] = sc.nextInt();
			q[i][2] = sc.nextInt();
		}
		sc.close();
		
		long[] a = new long[N];
		for(int i = 0;i < Q;++i) {
			for(int j = q[i][0]-1;j < q[i][1];++j)
				a[j] = q[i][2];
		}
		for(int i = 0;i < N;++i)
			System.out.println(a[i]);
	}
}