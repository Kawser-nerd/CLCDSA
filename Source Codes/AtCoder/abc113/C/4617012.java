import java.util.Comparator;
import java.util.TreeSet;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        City[] cities = new City[m];
        @SuppressWarnings("unchecked")
        TreeSet<City>[] a = new TreeSet[n];
        for (int i = 0, p; i < m; i++) {
            cities[i] = new City(p = scanner.nextInt(), scanner.nextInt());
            if (a[p - 1] == null)
                a[p - 1] = new TreeSet<>(Comparator.comparingInt(city -> city.y));
            a[p - 1].add(cities[i]);
        }
        for (TreeSet<City> citySet : a) {
            if (citySet != null) {
                int i = 0;
                for (City city : citySet) {
                    city.o = ++i;
                }
            }
        }
        for (City city : cities) {
            System.out.println(String.format("%06d%06d", city.p, city.o));
        }
    }

    static class City {
        int p, y, o;

        City(int p, int y) {
            this.p = p;
            this.y = y;
        }
    }
}