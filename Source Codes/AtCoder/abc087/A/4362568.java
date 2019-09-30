import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int X = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int ans = X - A;
        
        while(ans - B >= 0) ans -= B;
        
        System.out.println(ans);
    }
}