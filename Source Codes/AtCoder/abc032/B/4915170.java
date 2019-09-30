import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int k = sc.nextInt();

        int cnt = 0;
        for (int i = 0; i <= s.length()-k; i++) {
            if (s.indexOf(s.substring(i, i+k)) < i)
                continue;
            cnt++;
        }
        
        System.out.println(cnt);
    }
}