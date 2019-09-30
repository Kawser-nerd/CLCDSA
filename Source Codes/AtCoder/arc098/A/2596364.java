import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String s = sc.next();
        System.out.println(add(s));
    }

    private static int add(String s) {
        int[] right = new int[s.length()];
        int[] left = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) == 'W') {
                right[i] = right[i - 1] + 1;
            } else {
                right[i] = right[i - 1];
            }
        }
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s.charAt(i + 1) == 'E') {
                left[i] = left[i + 1] + 1;
            } else {
                left[i] = left[i + 1];
            }
        }
        int min = right.length;
        for (int i = 0; i < right.length; i++) {
            min = Math.min(min, left[i] + right[i]);
        }
        return min;
    }

}