import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String C1 = sc.next();
        String C2 = sc.next();
        
        for(int i = 0; i < 3; i++ ){
            if(C1.charAt(i) != C2.charAt(2 - i)){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}