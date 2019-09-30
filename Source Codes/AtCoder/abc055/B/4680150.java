import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	long ans = 1;
	for(int i = 1; i<=N; i++) {
	    ans *= i;
	    if(ans>Math.pow(10,9)+7) ans %= Math.pow(10,9)+7;
	}
	System.out.println((long)ans%((long)Math.pow(10,9)+7));
    }
}