import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H1 = sc.nextInt();
        int W1 = sc.nextInt();
        int H2 = sc.nextInt();
        int W2 = sc.nextInt();
        boolean flag = false;
        if (H1 == H2 || W1 == H2 || H1 == W2 || W1 == W2) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}