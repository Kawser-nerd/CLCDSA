import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        for (int i = 1; i <= X; i++) {
            if (Math.pow(i, 4) == X) {
                System.out.println(i);
                return;
            }
        }
    }
}