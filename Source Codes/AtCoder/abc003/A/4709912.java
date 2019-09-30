import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	double sum = 0;
	for ( int i = 1; i  <= N; i++ ) {
	    sum += 10000*i;
	}
	int ans = (int)sum/N;
	System.out.println(ans);
    }
}