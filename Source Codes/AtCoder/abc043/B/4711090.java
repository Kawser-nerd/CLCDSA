import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	List<String> list = new ArrayList<String>();
	for ( int i = 0; i < s.length(); i++ ) {
	    char tmp = s.charAt(i);
	    if ( tmp == '0' ) {
		list.add("0");
	    } else if ( tmp == '1' ) {
		list.add("1");
	    } else if ( tmp == 'B' ) {
		if ( !list.isEmpty() ) list.remove(list.size()-1);
	    }
	}
	for ( Iterator it = list.iterator(); it.hasNext();) {
	    System.out.print(it.next());
	}
	System.out.println();
    }
}