import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        char[] s = input.readLine().toCharArray();
        char[] t = input.readLine().toCharArray();
        Arrays.sort(s);
        Arrays.sort(t);
        for (int i = 0, j = t.length - 1; i < s.length && j > -1; i++, j--) {
            if (s[i] < t[j]) {
                System.out.println("Yes");
                return;
            } else if (s[i] > t[j]) {
                System.out.println("No");
                return;
            }
        }
        if (s.length < t.length) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}