import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String w = sc.next();
	int app[] = new int[26];
	Arrays.fill(app,0);
	for ( int i = 0; i < w.length(); i++ ) {
	    app[w.charAt(i)-'a']++;
	}
	boolean f = true;
	for ( int i = 0; i  < 26; i++ ) {
	    if ( app[i] % 2 == 1 ) {
		f = false;
		break;
	    }
	}
	if(f) System.out.println("Yes");
	else System.out.println("No");
    }
}