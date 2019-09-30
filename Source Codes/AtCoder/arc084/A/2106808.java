import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}

	Scanner sc = new Scanner(System.in);

	void run() {
		int n = sc.nextInt();
		
		int A[] = new int[n];
		int B[] = new int[n];
		int C[] = new int[n];
		
		
		for(int i = 0; i< n ; i++){
			A[i] = sc.nextInt();
		}
		for(int i = 0; i< n ; i++){
			B[i] = sc.nextInt();
		}
		for(int i = 0; i< n ; i++){
			C[i] = sc.nextInt();
		}
		
		
		Arrays.sort(A);
		Arrays.sort(B);
		Arrays.sort(C);
		
		
		int AB[] = new int[n];
		int ai = 0;
		int bi = 0;
		
		for( ; ai < n; ){
//			System.out.println(ai + " " + bi);
			if(A[ai] < B[bi]){
				AB[bi]++;
				ai++;
			}else{
				bi++;
				if(bi == n){
					break;
				}
				AB[bi] = AB[bi-1];
			}
		}
		bi ++;
		for(;bi < n ; bi ++){
			AB[bi] = AB[bi-1];
		}
//		System.out.println(Arrays.toString(A));
//		System.out.println(Arrays.toString(B));
//		System.out.println(Arrays.toString(AB));

		long BC[] = new long[n];
		bi = 0;
		int ci = 0;
		for( ;bi < n ; ){
			if(B[bi] < C[ci]){
				BC[ci] += AB[bi];
				bi++;
			}else{
				ci++;
				if(ci == n){
					break;
				}
				BC[ci] = BC[ci-1];
			}
		}

		ci ++;
		for(;ci < n ; ci ++){
			BC[ci] = BC[ci-1];
		}
//		System.out.println(Arrays.toString(BC));
		
		long res = 0L;
		for(int i = 0 ; i < n ; i++){
			res = res+ BC[i];
		}
		System.out.println(res);
		
	}
}