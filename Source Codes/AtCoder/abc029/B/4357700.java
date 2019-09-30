import java.util.Scanner;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] str = new String[12];
        for (int i = 0; i < 12; i++) {
            str[i] = sc.next();
        }
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < str[i].length(); j++) {
                if (str[i].charAt(j) == 'r') {
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}