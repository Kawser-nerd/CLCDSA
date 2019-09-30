import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {

        String s = sc.nextLine();
        long k = sc.nextLong();

        int numOfOnes = 0;
        int ans = 1;

        for (char ch : s.toCharArray()) {
            if (ch != '1') {
                ans = Integer.valueOf(String.valueOf(ch));
                break;
            } else {
                numOfOnes++;
            }
        }

        System.out.println(k <= numOfOnes ? "1" : ans);

    }

}