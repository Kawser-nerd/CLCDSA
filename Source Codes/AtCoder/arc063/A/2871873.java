import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            int cnt = 0;

            for (int i = 1; i < s.length(); i++) {
                char a = s.charAt(i);
                char b = s.charAt(i - 1);
                if ( a != b ) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
}