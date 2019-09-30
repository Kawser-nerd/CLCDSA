import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            int M = scanner.nextInt();
            TreeSet<Triple> map = new TreeSet<>((lhs,rhs)->lhs.Year - rhs.Year);

            for (int i = 0; i < M; i++) {
                int prefecture = scanner.nextInt();
                int year = scanner.nextInt();
                map.add(new Triple(i, prefecture, year));
            }

            Map<Integer, Integer> prefectureToCount = new HashMap<>();
            TreeMap<Integer, String> numToFormat = new TreeMap<>();
            for (final Triple triple : map) {
                int count = prefectureToCount.compute(triple.Prefecture, (k,v) -> v == null ? 1 : v + 1);
//                String format = String.format("%06d%06d", triple.Prefecture, count);
                String format = leftpad(triple.Prefecture) + leftpad(count);
                numToFormat.put(triple.num, format);
            }
            for (final String format : numToFormat.values()) {
                System.out.println(format);
            }
        }
    }

    static String leftpad(int v) {
        StringBuilder sb = new StringBuilder();
        while(v != 0) {
            sb.append(v % 10);
            v /= 10;
        }
        while(sb.length() < 6) {
            sb.append("0");
        }
        return sb.reverse().toString();
    }

    static class Triple {
        final int num;
        final int Prefecture;
        final int Year;

        Triple(int num, int prefecture, int y) {
            this.num = num;
            Prefecture = prefecture;
            Year = y;
        }
    }
}