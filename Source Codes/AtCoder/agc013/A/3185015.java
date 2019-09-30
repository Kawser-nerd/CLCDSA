import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int part = 1;
		Boolean I = true;
		Boolean J = false;
		for(int i=0;i<N;i++) {
			A[i] = sc.nextInt();
			if(i>0) {
				if(J) {
					if(A[i-1]<A[i] && !I) {
						part++;
						J = false;
					}else if(A[i-1]>A[i] && I) {
						part++;
						J = false;
					}
				}else {
					if(A[i-1]<A[i]) {
						J = true;
						I = true;
					}else if(A[i-1]>A[i]) {
						J = true;
						I = false;
					}
				}
				
			}
		}
		System.out.println(part);
	}
}