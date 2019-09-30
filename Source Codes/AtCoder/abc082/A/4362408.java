import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ave = (a + b) / 2;

        if( (a + b) % 2 == 1 ) ave++;
        
        System.out.println(ave);
    }
}