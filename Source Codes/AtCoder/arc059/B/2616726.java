import java.util.*;

public class Main {
    public void main(Scanner sc) {
        char s[] = sc.next().toCharArray();
        int len = s.length;

        int a = -1;
        int b = -1;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                a = i + 1;
                b = i + 2;
                break;
            }
            if (i + 2 < len && s[i] == s[i + 2]) {
                a = i + 1;
                b = i + 3;
                break;
            }
        }

        System.out.println(a + " " + b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}