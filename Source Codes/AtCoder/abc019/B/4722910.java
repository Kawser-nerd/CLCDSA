import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	s += "@";
	String tmp = "";
	int cnt = 0;
	String count = "";
	List<String> list = new ArrayList<>();
	for ( int i = 0; i < s.length(); i++ ) {
	    tmp = String.valueOf(s.charAt(i));
	    cnt = 0;
	    for ( int j = i; j < s.length(); j++ ){
		if ( tmp.charAt(0) == s.charAt(j) ) cnt++;
		else if ( //j == s.length()-1 ||
			   tmp.charAt(0) != s.charAt(j) ) {
		    count = String.valueOf(cnt);
		    list.add(tmp+count);
		    i = j-1;
		    //  System.out.println(j-1);
		    break;
		}
	    }
	}
	//count = String.valueOf(cnt);
	//list.add(tmp+count);	
	for ( Iterator<String> it = list.iterator(); it.hasNext(); ) {
	    String str = it.next();
	    System.out.print(str);
	}
	System.out.println();
    }
}