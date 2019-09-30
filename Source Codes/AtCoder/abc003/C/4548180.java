import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] rates = new int[n];

        for (int i = 0; i < n; i++) {
            rates[i] = sc.nextInt();
        }

        Arrays.sort(rates);

        int[] watchRates = Arrays.copyOfRange(rates, n - k, n);
//        for (int j : watchRates) {
//            System.out.println(j);
//        }
        double initRate = 0;
        for (int i = 0; i < watchRates.length; i++) {
            initRate = (initRate + watchRates[i]) / 2;
        }

        System.out.println(initRate);

    }

}