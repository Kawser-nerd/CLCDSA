import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String str = sc.next();

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < str.length() - 2; i++) {
            int value = Integer.valueOf(str.substring(i, i + 3));
            ans = Math.min(Math.abs(753 - value) , ans);
        }
        System.out.println(ans);
    }
}