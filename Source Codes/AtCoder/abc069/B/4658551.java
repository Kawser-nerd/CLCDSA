import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String a = sc.next();
	System.out.println(a.charAt(0) + "" + (a.length()-2) + "" + a.charAt(a.length()-1));
    }
}