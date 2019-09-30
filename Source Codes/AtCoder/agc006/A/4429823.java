import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        int count = n;
        for (int i = 0 ; i < n ; i++) {
            boolean match = true;
            for (int j = 0 ; j < n - i ; j++) {
                if (s[j + i] != t[j]) {
                    match = false;
                }
            }
            if (match) {
                count = i;
                break;
            }
        }
        System.out.println(n + count);
    }

}