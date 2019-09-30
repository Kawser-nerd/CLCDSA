import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Integer[] rate = new Integer[n];
        for(int i = 0; i < n; i++) {
            rate[i] = sc.nextInt();
        }
        Arrays.sort(rate, Comparator.reverseOrder());
        double answer = 0;
        for(int i = k-1; i >= 0; i--) {
            answer = (answer + rate[i]) / 2;
        }
        System.out.println(answer);
    }
}