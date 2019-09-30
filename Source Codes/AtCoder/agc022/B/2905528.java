import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int res[] = new int[n];
        res[0] = 2;
        res[1] = 3;
        int sum = 5;

        if (n <= 5) {
            for (int i = 2; i < n; i++) {
                sum += res[i - 1] + 1;
                for (int num = res[i - 1] + 1; num <= 30000; num++, sum++) {
                    if (sum % 6 != 0) {
                        continue;
                    }
                    res[i] = num;

                    boolean isOk = true;
                    for (int j = 0; j <= i; j++) {
                        if (gcd(res[j], sum) == 1) {
                            isOk = false;
                            break;
                        }
                    }

                    if (isOk) {
                        break;
                    }
                }
            }
        } else {
            for (int i = 2; i < n; i++) {
                res[i] = 6 * (i / 4) + (2 + i % 2) * (1 + (i % 4) / 2);
                sum += res[i];
            }

            switch (sum % 6) {
            case 2:
                res[4] = 6 * ((n + 1) / 4) + 6;
                sum = sum - 8 + res[4];
                break;
            case 3:
                res[5] = 6 * ((n + 1) / 4) + 6;
                sum = sum - 9 + res[5];
                break;
            case 5:
                res[5] = 6 * ((n + 1) / 4) + 4;
                sum = sum - 9 + res[5];
                break;
            default:
                break;
            }
        }

        System.out.println(Arrays.toString(res).replaceAll("[^ 0-9]", ""));
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}