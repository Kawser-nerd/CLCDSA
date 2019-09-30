import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        String ans = "EQUAL";
        if (a.length() > b.length()) {
            ans = "GREATER";
        } else if (a.length() < b.length()) {
            ans = "LESS";
        } else {
            for (int i = 0; i < a.length(); i++) {
                char ac = a.charAt(i);
                char bc = b.charAt(i);
                if (ac < bc) {
                    ans = "LESS";
                    break;
                } else if (ac > bc) {
                    ans = "GREATER";
                    break;
                }
            }
        }

        System.out.println(ans);
        sc.close();
    }
}