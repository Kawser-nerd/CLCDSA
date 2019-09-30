import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = sc.next().toCharArray();

        long Bcnt = 0;
        long cnt = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == 'W')
                cnt += Bcnt;
            if (s[i] == 'B')
                Bcnt++;
        }

        System.out.println(cnt);
    }
}