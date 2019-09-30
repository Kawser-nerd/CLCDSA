import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	String c = sc.next();
	for(int i = 0; i<s.length(); i++) {
	    String str = s.substring(i)+s.substring(0,i);
	    if(str.equals(c)) {
		System.out.println("Yes");
		return;
	    }
	}
	System.out.println("No");
    }
}