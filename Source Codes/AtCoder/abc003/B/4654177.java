import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	String a =	sc.next();
	String b =	sc.next();
	if(a.length()!=b.length()) {
            System.out.println("You will lose");
            return;
        }
	for(int i = 0; i<a.length(); i++) {
            char ca = a.charAt(i);
            char cb = b.charAt(i);
            if(ca!=cb) {
		if(ca=='@'&&(cb=='a' || cb=='t' || cb=='c' || cb=='o' || cb=='d' || cb=='e' || cb=='r')) {
                    continue;
		}
		if(cb=='@'&&(ca=='a' || ca=='t' || ca=='c' || ca=='o' || ca=='d' || ca=='e' || ca=='r')) {
                    continue;
		}
                System.out.println("You will lose");
                return;
            }
        }
	System.out.println("You can win");
    }
}