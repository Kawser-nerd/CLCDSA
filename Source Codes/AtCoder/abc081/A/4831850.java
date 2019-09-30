import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            char[] s = sc.next().toCharArray();
            int ans = 0;
            for (char c : s) {
                if ( c == '1' ) {
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}