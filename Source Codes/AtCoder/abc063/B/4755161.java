import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	HashSet<Character> set = new HashSet<Character>();
	char[] a = sc.next().toCharArray();
	for(int i = 0; i<a.length; i++) {
	    set.add(a[i]);
	}
	if(set.size() == a.length) {
	    System.out.println("yes");
	}else {
	    System.out.println("no");
	}
    }
}