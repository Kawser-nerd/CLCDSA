import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	String s1 = sc.next();
	String s2 = sc.next();
	for(int i = 0; i<s1.length(); i++) {
            if(s1.charAt(i)!=s2.charAt(s1.length()-1-i)) {
		System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}