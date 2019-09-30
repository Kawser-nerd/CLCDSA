import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        
        String ans = (x < 1200)? "ABC" : "ARC";
        
        System.out.print(ans);
    }
}