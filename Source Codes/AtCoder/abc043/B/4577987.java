import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        char[] ans = new char[s.length()];

        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'B') {
                if (index > 0)
                    index--;
            } else {
                ans[index++] = s.charAt(i);
            }
        }

        for (int i = 0; i < index; i++) {
            System.out.print(ans[i]);
        }
    }
}