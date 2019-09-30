import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String ans = "No";
        if(n%10==9||n/10==9)ans = "Yes";
        
        System.out.println(ans);
    }
}