import java.util.*;

class Main {
    void solve() {
        Scanner in = new Scanner(System.in);
        System.out.println(in.nextLine().replaceAll("[a-z]|[A-Z]", ""));
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}