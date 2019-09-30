import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if(a % 2 != 0) cnt++;
        }
        if(cnt % 2 != 0) System.out.println("NO");
        else System.out.println("YES");
        sc.close();
    }

}