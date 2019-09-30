import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        int diff_xa = (x -a > 0) ? x - a : -1 * (x -a);
        int diff_xb = (x -b > 0) ? x - b : -1 * (x -b);
        
        System.out.println((diff_xa < diff_xb) ? "A" : "B");
    }
}