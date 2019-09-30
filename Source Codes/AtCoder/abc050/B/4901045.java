import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] T = new int[N+1];
	int sum = 0;
	for(int i = 1; i<N+1; i++) {
	    T[i] = sc.nextInt();
	    sum += T[i];
	}
	int M = sc.nextInt();
	for(int i = 0; i<M; i++) {
	    int time = sum - T[sc.nextInt()] + sc.nextInt();
	    System.out.println(time);
	}
    }
}