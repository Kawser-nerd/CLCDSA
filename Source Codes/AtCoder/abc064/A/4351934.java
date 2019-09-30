import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int r = sc.nextInt();
        int g = sc.nextInt();
        int b = sc.nextInt();
        int num = r * 100 + g * 10 + b * 1;
        
        System.out.println((num % 4 == 0)? "YES" : "NO");
    }
}