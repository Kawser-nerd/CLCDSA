import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int hundred = N / 100;
        int one = N % 10;
        
        System.out.println((hundred == one)? "Yes" : "No");
    }
}