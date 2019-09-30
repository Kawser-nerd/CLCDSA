import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int sum = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                sum += i * j;
            }
        }

        int rest = sum - N;
        List<Integer> factorsList = new ArrayList<Integer>();
        factorsList.add(1);

        int index = 1;
        int tmp = rest;
        for (int i : new int[]{2, 3, 5, 7}) {
            while (tmp % i == 0) {
                tmp /= i;
                factorsList.add(i);
                index++;
            }
        }

        Integer[] factors = factorsList.toArray(new Integer[factorsList.size()]);

        TreeMap<Integer, Integer> first = new TreeMap<Integer, Integer>();
        do {
            for (int i = 0; i < factors.length; i++) {
                int num = 1;
                for (int j = 0; j <= i; j++) {
                    if (factors[j] != 0) {
                        num *= factors[j];
                    }
                }
                if (num <= 9 && rest / num <= 9) {
                    first.put(num, rest / num);
                }
            }
        } while (nextPermutation(factors));

        for (Map.Entry entry : first.entrySet()) {
            out.println(entry.getKey() + " x " + entry.getValue());
        }
    }

    // http://d.hatena.ne.jp/tomerun/20081203/1228321480
    // ??? ???????????????????????
    public static boolean nextPermutation(Integer[] a) {
        for (int i = a.length - 1; i > 0; --i) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1);
                int temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp;
                Arrays.sort(a, i, a.length);
                return true;
            }
        }
        return false;
    }

    // dest??????????????????????????????
    private static int find(int dest, Integer[] a, int s, int e) {
        if (s == e) {
            return s;
        }
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }
}