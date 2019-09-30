import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	Map<String, Integer> map = new HashMap<String,Integer>();
	for ( int i = 0; i < N; i++ ) {
	    String s = sc.next();
	    if ( map.get(s) == null ) {
		map.put(s,1);
	    } else {
		int cnt = map.get(s);
		map.replace(s,cnt+1);
	    }
	}
	int max = 0;
	String ans = "";
	for( Iterator<Map.Entry<String,Integer>> iterator = map.entrySet().iterator(); iterator.hasNext();) {
	    Map.Entry<String,Integer> entry = iterator.next();
	    if ( max < entry.getValue() ) {
		max = entry.getValue();
		ans = entry.getKey();
	    }
	}
	System.out.println(ans);
    }
}