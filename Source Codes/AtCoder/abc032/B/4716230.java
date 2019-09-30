import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	int k = sc.nextInt();
	if ( s.length() == k ) {
	    System.out.println(1);
	} else if ( s.length() < k ) {
	    System.out.println(0);	    
	} else {
	    Set<String> set = new HashSet<>();
	    for ( int i = 0; i < s.length()-(k-1); i++ ) {
		//	System.out.println(s.substring(i,i+k));
		set.add(s.substring(i,i+k));
	    }
	    System.out.println(set.size());
	}
    }
}