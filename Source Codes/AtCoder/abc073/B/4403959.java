import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans = 0;

        for(int i = 0; i < N; i++){
            int c = sc.nextInt();
            int r = sc.nextInt();
            
            ans += r - c + 1;
        }
        System.out.println(ans);
    }
}