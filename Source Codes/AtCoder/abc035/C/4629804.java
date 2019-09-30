import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int Q = sc.nextInt();
	int[] a = new int[N+1];
	for(int i = 0; i<Q; i++) {
	    int start = sc.nextInt();
	    int end = sc.nextInt();
	    a[start-1]++;
	    a[end]--;
	}
	int[] b = new int[N];
	b[0]=a[0];
	for(int i = 1; i<N; i++) {
	    b[i] = b[i-1]+a[i];
	}
	for(int i : b) {
	    System.out.print((i%2==0)?0:1);
	}
	System.out.println();
    }
}