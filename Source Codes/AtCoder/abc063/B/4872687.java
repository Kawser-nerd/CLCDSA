import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] check = new int[26];
        String s = sc.next();
        char[] cc = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            check[cc[i] - 'a']++;

        }
        boolean ans = true;
        for (int i = 0; i < s.length(); i++) {
            if (check[i] > 1) {
                ans = false;
            }
        }
        System.out.println(ans ? "yes" : "no");
        sc.close();
    }
}