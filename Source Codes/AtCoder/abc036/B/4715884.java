import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	String[] s = new String[N];
	for ( int i = 0; i < N; i++ ) {
	    s[i] = sc.next();
	}
	for ( int i = 0; i < N; i++ ) {
	    for ( int j = N-1; j >= 0; j-- ) {
		System.out.print(s[j].charAt(i));
	    }
	    System.out.println();
	}
    }
}