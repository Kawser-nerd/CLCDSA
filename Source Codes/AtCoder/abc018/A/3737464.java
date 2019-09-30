import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        new Main().main();
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());
        int c = Integer.parseInt(scanner.nextLine());

        System.out.println(this.rank(a, b, c));
        System.out.println(this.rank(b, a, c));
        System.out.println(this.rank(c, a, b));
    }

    private int rank(int self, int a, int b) {
        if (self < a && self < b) {
            return 3;
        } else if (self < a || self < b) {
            return 2;
        } else {
            return 1;
        }
    }
}