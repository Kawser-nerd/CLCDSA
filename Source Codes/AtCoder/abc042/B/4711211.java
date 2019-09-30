import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int L = sc.nextInt();
	List<String>list = new ArrayList<String>();
	for ( int i = 0; i < N; i++ ) {
	    String S = sc.next();
	    list.add(S);
	}
	Collections.sort(list);
	StringBuilder sb = new StringBuilder();
	for ( int i = 0; i < list.size(); i++ ) {
	    sb.append(list.get(i));
	}
	String s = sb.toString();
	System.out.println(s);
    }
}