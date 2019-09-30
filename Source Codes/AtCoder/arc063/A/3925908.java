import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        char[] s = sc.next().toCharArray();
        
        char preC = s[0];
        int count = 0;
        for (char c : s) {
            if (c != preC) {
                count++;
            }
            preC = c;
        }
        System.out.println(count);
    }
}