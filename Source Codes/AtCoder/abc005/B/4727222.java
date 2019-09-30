import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int ans = 10000;
	for ( int i = 0; i < N; i++ ) {
	    int t = sc.nextInt();
	    ans = Math.min(ans,t);
	}
	System.out.println(ans);
    }
}