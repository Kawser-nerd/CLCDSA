import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        String S = sc.next();

        if(S.contains("a") && S.contains("b") && S.contains("c")){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}