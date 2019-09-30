import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        String a = Integer.toString(A);
        String b = Integer.toString(B);
        int ans = Integer.valueOf(a + b) * 2;
        System.out.println(ans);
    }
}