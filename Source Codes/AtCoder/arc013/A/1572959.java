import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), l = in.nextInt(),
            p = in.nextInt(), q = in.nextInt(), r = in.nextInt(),
            max = 0;
        max = Math.max(max, (n/p) * (m/q) * (l/r));
        max = Math.max(max, (n/p) * (m/r) * (l/q));
        max = Math.max(max, (n/q) * (m/p) * (l/r));
        max = Math.max(max, (n/q) * (m/r) * (l/p));
        max = Math.max(max, (n/r) * (m/p) * (l/q));
        max = Math.max(max, (n/r) * (m/q) * (l/p));
        System.out.println(max);
    }
}