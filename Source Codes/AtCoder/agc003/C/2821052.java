import java.util.*;

public class Main {
    private class Data {
        int id, value;

        public Data(int id, int value) {
            this.id = id;
            this.value = value;
        }
    }

    public void main(Scanner sc) {
        int n = sc.nextInt();
        Data data[] = new Data[n];
        for (int i = 0; i < n; i++) {
            data[i] = new Data(i, sc.nextInt());
        }

        Arrays.sort(data, (d1, d2) -> d1.value - d2.value);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += Math.abs((data[i].id - i)) % 2;
        }

        System.out.println(cnt / 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}