import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] n = sc.next().split("");
        for (int i = 0; i < n.length; i++) {
            if ("1".equals(n[i])) {
                n[i] = "9";
                continue;
            }
            if ("9".equals(n[i])) {
                n[i] = "1";
            }
        }
        StringJoiner sj = new StringJoiner("");
        for (int i = 0; i < n.length; i++) {
            sj.add(n[i]);
        }
        System.out.println(sj.toString());
    }

}