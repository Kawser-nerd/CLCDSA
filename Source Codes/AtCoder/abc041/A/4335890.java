import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        int i = sc.nextInt();

        //????i?????  
        char ans = s.charAt(i - 1);
        
        System.out.println(ans);
    }
}