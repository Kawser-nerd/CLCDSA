import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int i = 0;

        StringBuilder builder = new StringBuilder();
        while (i < s.length()) {
            char ch = s.charAt(i);
            int count = this.countChar(s.substring(i, s.length()), ch);
            builder.append(String.format("%c%d", ch, count));
            i += count;
        }
        System.out.println(builder.toString());
    }

    private int countChar(String s, char ch) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
}