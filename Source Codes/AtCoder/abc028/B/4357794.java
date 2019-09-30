import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int[] c = new int[6];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                c[0]++;
            } else if (s.charAt(i) == 'B') {
                c[1]++;
            } else if (s.charAt(i) == 'C') {
                c[2]++;
            } else if (s.charAt(i) == 'D') {
                c[3]++;
            } else if (s.charAt(i) == 'E') {
                c[4]++;
            } else if (s.charAt(i) == 'F') {
                c[5]++;
            }
        }
        System.out.printf("%d %d %d %d %d %d%n", c[0], c[1], c[2], c[3], c[4], c[5]);
    }
}