import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = Integer.parseInt(sc.next());
	int[] T = new int[N+1];
	int sum = 0;
	for(int i = 1; i<N+1; i++) {
	    T[i] = Integer.parseInt(sc.next());
	    sum += T[i];
	}
	int M = sc.nextInt();
	for(int i = 0; i<M; i++) {
	    int time = sum - T[Integer.parseInt(sc.next())] + Integer.parseInt(sc.next());
	    System.out.println(time);
	}
    }
}