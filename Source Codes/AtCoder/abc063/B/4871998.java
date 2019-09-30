import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean[] c = new boolean[26];
        for (int i = 0; i < s.length(); i++) {
            char ssc = s.charAt(i);
            int pos = (int) ssc - 97;
            if (c[pos]) {
                System.out.println("no");
                return;
            } else {
                c[pos] = true;
            }

        }
        sc.close();
        System.out.println("yes");
    }
}