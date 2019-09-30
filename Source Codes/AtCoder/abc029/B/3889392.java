import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S[] = new String[12];
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            S[i] = sc.next();
            if (S[i].contains("r")) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}