import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        
        System.out.println(A * N < B ?  A * N : B );
    }
}