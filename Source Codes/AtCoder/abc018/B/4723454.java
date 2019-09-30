import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	int N = sc.nextInt();
	String ans ="";
	StringBuilder sb = new StringBuilder(S);
	for ( int i = 0; i < N; i++ ) {
	    int l = sc.nextInt();
	    int r = sc.nextInt();
	    l--;
	    String s1 = sb.substring(l,r);
	    StringBuilder ss1 = new StringBuilder(s1);
	    StringBuilder s2 = ss1.reverse();
	    String st = s2.toString();
	    StringBuilder s3 = sb.replace(l,r,st);
	    ans = s3.toString();

	}
	    System.out.println(ans);	
    }
}