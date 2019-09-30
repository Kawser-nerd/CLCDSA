import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        str = str.substring(0, 1).toUpperCase() + str.substring(1).toLowerCase();
 
        System.out.println(str);
    }
}