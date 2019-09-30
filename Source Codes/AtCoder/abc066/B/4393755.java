import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        
        S = S.substring(0, S.length() - 1);
        while(S.length() > 1){
            if(S.length() % 2 == 1) S = S.substring(0,S.length() - 1);

            if(S.substring(0,S.length() / 2).equals(S.substring(S.length() / 2, S.length()))){
                System.out.println(S.length());
                break;
            }
            S = S.substring(0,S.length() - 1);
        }
    }
}