import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	int N = sc.nextInt();
	StringBuilder sb = new StringBuilder(S);
	for ( int i = 0; i < N; i++ ) {
	    int l = sc.nextInt();
	    int r = sc.nextInt();
	    S = func(S,l,r);
	}
	System.out.println(S);
    }
    
    private static String func(String s, int l,int r) {
	StringBuilder sb = new StringBuilder();
	sb.append(s.substring(0,l-1));
	sb.append(new StringBuilder(s.substring(l-1,r)).reverse().toString());
	sb.append(s.substring(r,s.length()));
	return sb.toString();
    }

}