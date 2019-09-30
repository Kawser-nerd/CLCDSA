import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int a = sc.nextInt();
	int b = sc.nextInt();
	int K = sc.nextInt();
	int P[] = new int[101];
	int visited[] = new int[101];
	Arrays.fill(visited,0);	
	for ( int i = 0; i < K; i++ ) {
	    P[i] = sc.nextInt();
	    if ( P[i] == a || P[i] == b ) {
		System.out.println("NO");
		return;
	    }
	    if ( visited[P[i]] > 0 ) {
		System.out.println("NO");
		return;		
	    }
	    visited[P[i]]++;
	}
	System.out.println("YES");

    }
}