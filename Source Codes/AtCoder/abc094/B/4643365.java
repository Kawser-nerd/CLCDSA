import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] A = new int[M];
		for(int i = 0;i < M;i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		// N???
		int costN = 0;
		for(int i = X + 1;i <= N;i++) {
			for(int k = 0;k < M;k++) {
				if(A[k] == i) costN++;
			}
		}
		// 0???
		int costZ = 0;
		for(int i = X - 1;i >= 0;i--) {
			for(int k = 0;k < M;k++) {
				if(A[k] == i) costZ++;
			}
		}
		System.out.println(Math.min(costN,costZ));
	}

}