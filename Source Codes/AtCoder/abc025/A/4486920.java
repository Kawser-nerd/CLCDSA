import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt()-1;
        System.out.println(s.charAt(n/5)+""+s.charAt(n%5));
    }
}