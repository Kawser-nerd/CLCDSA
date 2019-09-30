import java.util.*;
import java.util.stream.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();

        int road[] = new int[n];
        init(n, road);
        for (int i = 0; i < k; i++) {
            link(sc.nextInt(), sc.nextInt(), road);
        }

        int train[] = new int[n];
        init(n, train);
        for (int i = 0; i < l; i++) {
            link(sc.nextInt(), sc.nextInt(), train);
        }

        String keys[] = new String[n];
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            keys[i] = root(road[i], road) + "," + root(train[i], train);
            map.compute(keys[i], (key, value) -> value == null ? 1 : (value + 1));
        }

        System.out.println(Arrays.stream(keys).map(tgt -> String.valueOf(map.get(tgt)))
            .collect(Collectors.joining(" ")));
    }

    public void init(int n, int data[]) {
        for (int i = 0; i < n; i++) {
            data[i] = i + 1;
        }
    }

    public void link(int x, int y, int data[]) {
        data[root(x, data) - 1] = root(y, data);
    }

    public boolean isSame(int x, int y, int data[]) {
        return root(x, data) == root(y, data);
    }

    public int root(int p, int data[]) {
        return (data[p - 1] == p) ? p : (data[p - 1] = root(data[p - 1], data));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}