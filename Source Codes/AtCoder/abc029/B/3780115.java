import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int count = 0;
        for (int i = 0; i < 12; i++) {
            String s = scanner.nextLine();
            if (s.indexOf("r") >= 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}