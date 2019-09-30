import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        long X = sc.nextLong();
        long Y = sc.nextLong();
        if (Math.abs(X - Y) <= 1) {
            System.out.println("Brown");
        } else {
            System.out.println("Alice");
        }
    }
}