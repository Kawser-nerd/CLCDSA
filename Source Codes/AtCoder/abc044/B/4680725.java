import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String str = sc.next();
	HashMap<Character, Integer> map = new HashMap<Character, Integer>();
	for(int i = 0; i<str.length(); i++) {
	    char c = str.charAt(i);
	    int cnt = (map.containsKey(c))?map.get(c):0;
	    map.put(c,cnt+1);
	}
	for(char c: map.keySet()) {
	    if(map.get(c)%2!=0) {
		System.out.println("No");
		return;
	    }
	}
	System.out.println("Yes");
    }
}