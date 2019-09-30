import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int[] count = new int[6];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'A']++;
        }
        for (int i = 0; i < 6; i++) {
            System.out.print(count[i]);
            if (i == 5) {
                System.out.print("\n");
            } else {
                System.out.print(" ");
            }
        }
    }
}