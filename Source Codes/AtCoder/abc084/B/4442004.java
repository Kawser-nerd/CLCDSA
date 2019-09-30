import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        String S = sc.next();
        
        if(S.substring(0,A).contains("-")){
            System.out.println("No");
            return;
        }
        if(!(S.substring(A,A + 1).contains("-"))){
            System.out.println("No");
            return;
        }
        if(S.substring(A + 1, A + B + 1).contains("-")){
            System.out.println("No");
            return;
        }
        System.out.println("Yes");
    }
}