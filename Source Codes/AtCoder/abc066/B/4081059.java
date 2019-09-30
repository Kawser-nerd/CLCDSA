import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        for (int i = s.length() - 2; i >= 2; i -= 2) {
            String former = s.substring(0, i / 2);
            String latter = s.substring(i / 2, i);
            if (former.equals(latter)) {
                System.out.println(former.length() + latter.length());
                return;
            }
        }
    }

}