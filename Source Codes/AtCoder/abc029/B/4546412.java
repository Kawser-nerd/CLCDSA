import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            String s = sc.next();
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c == 'r') {
                    ans++;
                    break;
                }
            }

        }
        System.out.println(ans);
        sc.close();
    }
}