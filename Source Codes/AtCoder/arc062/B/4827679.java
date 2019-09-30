import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int ans = s.length /2;
        for (int i = 0; i < s.length; i++) {
            if(s[i] == 'p') ans--;
        }

        System.out.println(ans);
        sc.close();
    }
}