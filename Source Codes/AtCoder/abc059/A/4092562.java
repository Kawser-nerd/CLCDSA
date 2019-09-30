import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String A = sc.next();
        String B = sc.next();
        String C = sc.next();
        
        String ans = A.charAt(0) +"" +B.charAt(0)+"" + C.charAt(0);
        
        System.out.println(ans.toUpperCase());
    }
}