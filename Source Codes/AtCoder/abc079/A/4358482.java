import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String X = sc.next();
        
        if(X.charAt(0) == X.charAt(1) && X.charAt(1) == X.charAt(2)){
            System.out.println("Yes");
        }else if(X.charAt(1) == X.charAt(2) && X.charAt(2) == X.charAt(3)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}