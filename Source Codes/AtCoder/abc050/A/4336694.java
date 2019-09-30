import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        char op = sc.next().charAt(0);
        int b = sc.nextInt();
        
        //?????
        int ans = (op == '+')? a + b : a - b ;
        System.out.println(ans);
    }
}