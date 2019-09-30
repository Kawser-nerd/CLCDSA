import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int plus = 200*(n/15);
        System.out.println(n*800-plus);
    }
}