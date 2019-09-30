import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int L = 0;
        int L_max = 0;
        for(int i = 0; i < n; i ++) {
            int l = sc.nextInt();
            L += l;
            L_max = Math.max(L_max, l);
        }
        if(L_max < L - L_max) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}