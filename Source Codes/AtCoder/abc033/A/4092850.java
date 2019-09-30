import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        System.out.println(s.replaceAll(s.charAt(0)+"", "").length() == 0 ? "SAME": "DIFFERENT");
    }
}