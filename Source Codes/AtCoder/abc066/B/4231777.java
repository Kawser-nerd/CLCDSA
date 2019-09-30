import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        if (s.length() % 2 == 0)
            s = s.substring(0, s.length()-1);

        int ans = 0;
        for (int i = 1; i < s.length(); i += 2) {
            int index = s.length() - i;
            String s1 = s.substring(0, index/2);
            String s2 = s.substring(index/2, index);
            if (s1.equals(s2)) {
                ans = index;
                break;
            }
        }

        System.out.println(ans);
    }
}