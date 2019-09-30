import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        while (!isAllSame(N)) {
            N++;
        }

        System.out.println(N);
    }

    private static boolean isAllSame(int N) {
        String str = String.valueOf(N);
        char[] chars = str.toCharArray();

        char c = chars[0];
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != c) return false;
        }
        return true;
    }

}