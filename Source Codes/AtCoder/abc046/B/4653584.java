import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int K = sc.nextInt();
	long ans = K;
	for(int i = 1; i<N;i++) {
	    ans*=(K-1);
	}
	System.out.println(ans);
    }
}