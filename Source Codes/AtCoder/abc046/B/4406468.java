import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static boolean found = false;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        long ans = k;

        for (int i = 0; i < n - 1; i++) {
            ans *= (k - 1);
        }
        System.out.println(ans);
    }

}