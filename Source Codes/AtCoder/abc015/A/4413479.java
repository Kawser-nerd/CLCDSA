import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String n = sc.next(), m = sc.next();
        if (n.length() > m.length())
            System.out.println(n);
        else
            System.out.println(m);
    }
}