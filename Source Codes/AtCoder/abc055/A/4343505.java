import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int x = N * 800;
        int y = N / 15 * 200;
        int ans = x - y;

        System.out.print(ans);
    }
}