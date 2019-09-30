import java.util.*;
import static java.lang.Math.*;

public class Main {
	static int A, B, C, N;
	static int[] L;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt();
		L = new int[N];
		A= sc.nextInt();
		B= sc.nextInt();
		C= sc.nextInt();
		int i;
		for(i = 0; i < N; i++) {
			L[i] = sc.nextInt();
		}
		sc.close();
		sc = null;
		System.out.println(calmp(0,0,0,0));
	}
	static int calmp(int n, int a, int b, int c) {
		if(n == N) {
		    return (min(min(a,b),c) > 0) ? (abs(A-a)+abs(B-b)+abs(C-c)-30) : 3000;}
		int mp0 = calmp(n+1, a, b, c);
		int mp1 = calmp(n+1, a+L[n], b, c) + 10;
		int mp2 = calmp(n+1, a, b+L[n], c) + 10;
		int mp3 = calmp(n+1, a, b, c+L[n]) + 10;
		return min(min(mp0, mp1),min(mp2, mp3));
	}
}