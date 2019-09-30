import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int length = s.length();
        
        System.out.println("" + s.charAt(0) + (length - 2) + s.charAt(length - 1)) ;
    }
}