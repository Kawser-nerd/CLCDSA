import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int min = 999;

        for (int i = 0; i < s.length() - 2; i++) {
            String part = s.substring(i,i + 3);
            int number = Integer.parseInt(part);
            int difference = Math.abs(number - 753);
            if (difference < min) {
                min = difference;
            }
        }
        System.out.println(min);
    }
}