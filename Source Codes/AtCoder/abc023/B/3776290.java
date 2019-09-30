import java.util.*;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String s = scanner.nextLine();
        System.out.println(this.times(n, s));
    }

    private int times(int n, String s) {
        if (n % 2 == 0) {
            return -1;
        }
        int ret = (n - 1) / 2;
        char ch;
        if (ret % 3 == 1) {
            ch = 'a';
        } else if (ret % 3 == 2) {
            ch = 'c';
        } else {
            ch = 'b';
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != ch) {
                return -1;
            }

            if (ch == 'c') {
                ch = 'a';
            } else {
                ch++;
            }
        }

        return ret;
    }
}