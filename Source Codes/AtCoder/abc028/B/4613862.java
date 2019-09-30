import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] ans = new int[6];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int b = (int) c - 65;
            ans[b]++;
        }
        for (int i = 0; i < 6; i++) {
            System.out.print(ans[i]);
            if (i != 5) {
                System.out.print(" ");
            }
        }
        System.out.println();
        sc.close();
    }
}