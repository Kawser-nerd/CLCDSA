import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == 'I') {
                cnt++;
                if (ans < cnt) {
                    ans = cnt;
                }
            } else {
                cnt--;
            }
        }
        System.out.println(ans);
        sc.close();
    }
}