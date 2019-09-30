import java.util.Scanner;

class Main {
    static String a;
    static String b;
    static String c;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        a = sc.next();
        b = sc.next();
        c = sc.next();
        char ac = a.charAt(0);
        int ans = 0;
        if (ac == 'a') {
            ans = DisCard(1);
        } else if (ac == 'b') {
            ans = DisCard(2);
        } else {
            ans = DisCard(3);
        }
        String answ = "";
        if (ans == 1) {
            answ = "A";
        } else if (ans == 2) {
            answ = "B";
        } else {
            answ = "C";
        }
        System.out.println(answ);
        sc.close();
    }

    public static int DisCard(int player) {
        if (player == 1) {
            if (a.length() == 0) {
                return 1;
            } else {
                char c = a.charAt(0);
                a = a.substring(1);
                if (c == 'a') {
                    return DisCard(1);
                } else if (c == 'b') {
                    return DisCard(2);
                } else {
                    return DisCard(3);
                }
            }
        } else if (player == 2) {
            if (b.length() == 0) {
                return 2;
            } else {
                char c = b.charAt(0);
                b = b.substring(1);
                if (c == 'a') {
                    return DisCard(1);
                } else if (c == 'b') {
                    return DisCard(2);
                } else {
                    return DisCard(3);
                }
            }
        } else {
            if (c.length() == 0) {
                return 3;
            } else {
                char cha = c.charAt(0);
                c = c.substring(1);
                if (cha == 'a') {
                    return DisCard(1);
                } else if (cha == 'b') {
                    return DisCard(2);
                } else {
                    return DisCard(3);
                }
            }
        }
    }
}