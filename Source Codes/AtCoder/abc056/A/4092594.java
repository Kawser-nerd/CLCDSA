import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String A = sc.next();
        String B = sc.next();
        
        boolean a = A.equals("H");
        boolean b = B.equals("H");
        b = a?b:!b;
        System.out.println(b?"H": "D");
    }
}