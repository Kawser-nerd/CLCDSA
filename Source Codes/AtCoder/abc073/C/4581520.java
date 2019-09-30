import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        HashSet<Long> set = new HashSet<>();
        for (int i = 0; i < N; i++) {
            long value = sc.nextLong();
            if (set.contains(value)) {
                set.remove(value);
            } else {
                set.add(value);
            }
        }
        System.out.println(set.size());
    }
}