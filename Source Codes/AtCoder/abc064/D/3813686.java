import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();

        int rightCnt = 0;
        int leftCnt = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                rightCnt++;
            }
            if (s.charAt(i) == ')') {
                if (rightCnt == 0) {
                    leftCnt++;
                } else {
                    rightCnt--;
                }
            }
        }

        String ans = "";
        for (int i = 0; i < leftCnt; i++) {
            ans += "(";
        }
        ans += s;

        for (int i = 0; i < rightCnt; i++) {
            ans += ")";
        }
        System.out.println(ans);
    }
}