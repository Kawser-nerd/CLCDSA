import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] arrivalTime = new int[n];
        for (int i = 0; i < n - 1; i++) {
            int spentTime = sc.nextInt();
            int startTime = sc.nextInt();
            int frequentTime = sc.nextInt();
            for (int j = 0; j <= i; j++) {
                if (arrivalTime[j] < startTime) {
                    arrivalTime[j] = startTime;
                }

                if (arrivalTime[j] % frequentTime != 0) {
                    arrivalTime[j] += frequentTime - (arrivalTime[j] % frequentTime);
                }
                arrivalTime[j] += spentTime;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(arrivalTime[i]);
        }
    }
}