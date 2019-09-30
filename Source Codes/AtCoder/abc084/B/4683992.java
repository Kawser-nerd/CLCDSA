import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int first = sc.nextInt();
	int second = sc.nextInt();
	String str = sc.next();
	if(str.length()!=(first+second+1)) {
	    System.out.println("No");
	    return;
	}
	for(int i = 0; i<str.length(); i++) {
	    char c = str.charAt(i);
	    if(i==first) {
		if(c!='-') {
		    System.out.println("No");
		    return;
		}
	    }else {
		if(c=='-') {
		    System.out.println("No");
		    return;
		}
	    }
	}
	System.out.println("Yes");
    }
}