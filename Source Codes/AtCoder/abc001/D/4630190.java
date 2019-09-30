import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        List<Pair> pairs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String str = sc.next();
            int start = moveUp(floor(Integer.parseInt(str.substring(0, 4))));
            int end = moveUp(ceil(Integer.parseInt(str.substring(5))));
            pairs.add(new Pair(start, end));
        }

        pairs = pairs.stream().sorted(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return Integer.compare(o1.first, o2.first);
            }
        }).distinct().collect(Collectors.toList());

        for (int i = 0; i < pairs.size(); i++) {
            int first = pairs.get(i).first, second = pairs.get(i).second;
            for (int j = i + 1; j < pairs.size(); j++) {
                int nextFirst = pairs.get(j).first, nextSecond = pairs.get(j).second;
                if (second < nextFirst) {
                    i = j - 1;
                    break;
                }
                if (j == pairs.size() - 1) {
                    i = j;
                }
                second = Math.max(second, nextSecond);
            }
            System.out.println(String.format("%04d-%04d", first, second));
        }
    }

    private static int floor(int x) {
        if (x % 10 > 0 && x % 10 < 5) {
            return x - x % 10;
        } else if (x % 10 > 5) {
            return x - (x % 10 - 5);
        } else {
            return x;
        }
    }

    private static int ceil(int x) {
        if (x % 10 > 0 && x % 10 < 5) {
            return x + (5 - x % 10);
        } else if (x % 10 > 5) {
            return x + (10 - x % 10);
        } else {
            return x;
        }
    }

    private static int moveUp(int x) {
        if (x % 100 == 60) {
            return x + 40;
        } else {
            return x;
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}