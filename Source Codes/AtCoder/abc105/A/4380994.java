import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();

        System.out.println(N % R == 0 ?  0 : 1);
    }
}