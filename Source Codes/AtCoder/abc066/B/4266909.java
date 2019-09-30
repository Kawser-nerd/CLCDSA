import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // input
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n / 2 + 1; i++) {
            String fs = s.substring(0, i);
            String ls = s.substring(i, 2 * i);
            if (fs.equals(ls)) {
                if(i * 2 == n){
                    break;
                }
             ans = i * 2;
            }
        }
        System.out.println(ans);
    }

}