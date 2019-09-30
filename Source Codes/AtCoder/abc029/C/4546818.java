import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        Print(n, "");

    }

    public static void Print(int pos, String s) {
        if (pos == 1) {
            System.out.println(s + "a");
            System.out.println(s + "b");
            System.out.println(s + "c");
        } else {
            Print(pos - 1, s + "a");
            Print(pos - 1, s + "b");
            Print(pos - 1, s + "c");
        }
    }
}