import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A[] = new int[N];
		int Max=0, Min=Integer.MAX_VALUE;
		for(int i = 0; i<N; i++) {
			A[i] = sc.nextInt();
			if(A[i]>Max)Max=A[i];
			if(A[i]<Min)Min=A[i];
		}
		System.out.println(Max-Min);
		sc.close();
	}

}