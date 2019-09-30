import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	int app[] = new int[6];
	Arrays.fill(app,0);
	for ( int i = 0; i < S.length(); i++ ) {
	    app[S.charAt(i)-'A']++;
	}
	for ( int i = 0; i < 6; i++ ) {
	    if ( i == 5 ) System.out.println(app[i]);
	    else System.out.print(app[i] + " ");
	}

    }
}