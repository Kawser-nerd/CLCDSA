import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int tp = X / 10;
        int op = X % 10;
        System.out.println(tp + op);
    }
}