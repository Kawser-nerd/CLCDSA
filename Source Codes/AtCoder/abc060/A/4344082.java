import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String A = sc.next();
        String B = sc.next();
        String C = sc.next();
        
        int a = A.length();
        int b = B.length();
        int c = C.length();
        
        if(A.charAt(a-1) == B.charAt(0) && B.charAt(b-1) == C.charAt(0)){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }
}