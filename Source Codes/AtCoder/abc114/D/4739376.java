import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        HashMap<Integer, Integer> primeCount = new HashMap<>();

        primeCount.put(1, 1);
        for (int i = 2; i <= N; i++) {
            int value = i;
            for (int j = 2; j <= i; j++) { // 2~n??
                while (value % j == 0) {   // ???????????????????????
                    primeCount.put(j, primeCount.containsKey(j) ? primeCount.get(j) + 1 : 1);
                    value = value / j;     // ???????
                }
            }
        }
        
        int ans = 0;
        //  4,4,2
        for (Map.Entry<Integer, Integer> entry0 : primeCount.entrySet()) {
            for (Map.Entry<Integer, Integer> entry1 : primeCount.entrySet()) {
                for (Map.Entry<Integer, Integer> entry2 : primeCount.entrySet()) {
                    if (entry0.getKey() == entry1.getKey()) continue;
                    if (entry0.getKey() == entry2.getKey()) continue;
                    if (entry1.getKey() == entry2.getKey()) continue;
                    if (entry1.getKey() > entry2.getKey()) continue;
                    if (entry0.getValue() >= 2 && entry1.getValue() >= 4 && entry2.getValue() >= 4) ans++;
                }
            }
        }

        //  24,2
        //  4,14
        for (Map.Entry<Integer, Integer> entry0 : primeCount.entrySet()) {
            for (Map.Entry<Integer, Integer> entry1 : primeCount.entrySet()) {
                if (entry0.getKey() == entry1.getKey()) continue;
                if (entry0.getValue() >= 4 && entry1.getValue() >= 14) ans++;
                if (entry0.getValue() >= 2 && entry1.getValue() >= 24) ans++;
            }
        }

        //  74
        for (Integer count : primeCount.values()) {
            if (count >= 74) ans++;
        }

        System.out.println(ans);
    }


}