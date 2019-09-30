import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	int K = sc.nextInt();
	int S = sc.nextInt();
	int T = sc.nextInt();
	int ans = A*S+B*T;
	if ( S+T >= K ) ans -= C*(S+T);
	System.out.println(ans);
    }
}