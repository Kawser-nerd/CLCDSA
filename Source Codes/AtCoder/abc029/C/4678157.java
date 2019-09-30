import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        char[] chars = new char[]{ 'a', 'b', 'c' };

        for (int i = 0; i <(int) Math.pow(3, N); i++) {

            int tmp = i;
            String pattern = "";
            for (int j = N - 1; j >= 0; j--) {
                int count = tmp / ((int)Math.pow(3,j));
                pattern += chars[count];
                tmp -= count * ((int)Math.pow(3,j));
            }
            System.out.println(pattern);
        }
    }
}