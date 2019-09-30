import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int D = sc.nextInt();
		int X = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0;i < N;i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		int sum = 0;
		for(int i = 0;i < N;i++) {
			if(A[i] == 1) sum += D; 
			else if(D / A[i] >= 1) {
				sum += (D / A[i]) + 1;
				if(D % A[i] == 0) sum--;
			}
			else if(D / A[i] == 0) sum++;
		}
		sum += X;
		System.out.println(sum);
	}
	
}