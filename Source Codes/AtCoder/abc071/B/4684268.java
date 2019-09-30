import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	HashSet<Character> set = new HashSet<Character>();
	String str = sc.next();
	for(int i = 0; i<str.length(); i++) {
	    set.add(str.charAt(i));
	}
	for(int i = 0; i<26; i++) {
	    if(!set.contains((char)('a'+i))) {
		System.out.println((char)('a'+i));
		return;
	    }
	}
	System.out.println("None");
    }
}