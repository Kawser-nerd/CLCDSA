import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int sum = 100 * a + 10 * b + c;
        String ans = (sum % 4 == 0)? "YES" : "NO";
        System.out.println(ans);
    }    
}