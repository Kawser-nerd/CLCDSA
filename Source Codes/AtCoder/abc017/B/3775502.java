import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        if (this.isChoku(str)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private boolean isChoku(String s) {
        if (s.equals("")) {
            return true;
        }

        int last = s.length() - 1;
        if (s.charAt(last) == 'o' || s.charAt(last) == 'k' || s.charAt(last) == 'u') {
            return this.isChoku(s.substring(0, last));
        } else if (s.substring(Math.max(0, last - 1), last + 1).equals("ch")) {
            return this.isChoku(s.substring(0, last - 1));
        } else {
            return false;
        }
    }
}