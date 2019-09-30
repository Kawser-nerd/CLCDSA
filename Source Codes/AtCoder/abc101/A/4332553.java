import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s = sc.next().split("");
        int count = 0;
        for (int i = 0; i < s.length; i++) {
            if ("+".equals(s[i])) {
                count++;
                continue;
            }
            count--;
        }
        System.out.println(count);
    }

}