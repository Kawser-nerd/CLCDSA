import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans = 1;
        while(ans<=N) {
            ans *= 2;
        }
        System.out.println(ans/2);
    }
}