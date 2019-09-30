import java.util.*;
public class Main {

    private static int calc(int x) {
        int ret = 0;
        while(x % 100 == 0) {
            x /= 100;
            ++ret;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int n = sc.nextInt();
        int count = 0;
        int value = 0;
        while(count < n) {
            ++value;
            if(calc(value) == d) ++count;
        }
        System.out.println(value);
        sc.close();
    }

}