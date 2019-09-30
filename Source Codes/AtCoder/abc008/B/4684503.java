import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	HashMap<String, Integer> map = new HashMap<String, Integer>();
	for(int i = 0; i<N; i++) {
	    String name = sc.next();
	    int c = map.containsKey(name)?map.get(name):0;
	    map.put(name, c+1);
	}
	int max = 0;
	String ans = "";
	for(String str : map.keySet()) {
	    if(max<map.get(str)) {
		max = map.get(str);
		ans = str;
	    }
	}
	System.out.println(ans);
    }
}