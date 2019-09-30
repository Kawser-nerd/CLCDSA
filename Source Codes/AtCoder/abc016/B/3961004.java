import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        if (A + B == C && A - B != C) {
            System.out.println("+");
        } else if (A - B == C && A + B != C) {
            System.out.println("-");
        } else if (A + B != C && A - B != C) {
            System.out.println("!");
        } else {
            System.out.println("?");
        }
    }
}