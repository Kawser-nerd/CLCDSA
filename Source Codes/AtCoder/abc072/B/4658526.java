import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	String a =	sc.next();
	for(int i = 0; i<a.length();i++) {
            if(i%2==0)System.out.print(a.charAt(i));
	}
        System.out.println();
    }
}