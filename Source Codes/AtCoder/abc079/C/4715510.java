import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int a = Integer.parseInt(s.substring(0, 1));
        int b = Integer.parseInt(s.substring(1, 2));
        int c = Integer.parseInt(s.substring(2, 3));
        int d = Integer.parseInt(s.substring(3, 4));

        sc.close();

        boolean[] ifplus = {true, false};
        for(boolean op1 : ifplus) {
            for(boolean op2 : ifplus) {
                for(boolean op3 : ifplus) {
                    int ans = a;
                    ans += op1? b : -b;
                    ans += op2? c : -c;
                    ans += op3? d : -d;

                    if(ans == 7) {
                        StringBuilder sb = new StringBuilder();
                        sb.append(a);
                        sb.append(op1? '+' : '-');
                        sb.append(b);
                        sb.append(op2? '+' : '-');
                        sb.append(c);
                        sb.append(op3? '+' : '-');
                        sb.append(d);
                        sb.append("=7");
                        System.out.println(sb);
                        System.exit(0);
                    }
                }
            }
        }
    }
}