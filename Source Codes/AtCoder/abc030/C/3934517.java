import java.util.Arrays;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        Pair[] pairs = new Pair[n + m];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextInt();
            Pair ps = new Pair();
            ps.start = a[i];
            ps.goal = a[i] + x;
            ps.dir = 1;
            pairs[i] = ps;
        }
        for (int i = 0 ; i < m ; i++) {
            b[i] = sc.nextInt();
            Pair ps = new Pair();
            ps.start = b[i];
            ps.goal = b[i] + y;
            ps.dir = -1;
            pairs[i + n] = ps;
        }
        Arrays.sort(pairs);
        int count = 0;
        int t = 0;
        int nowdir = 1;
        for (int i = 0 ; i < n + m ; i++) {
            int start = pairs[i].start;
            int goal = pairs[i].goal;
            int dir = pairs[i].dir;
            if (t <= start && nowdir == dir) {
                count++;
                t = goal;
                nowdir *= -1;
            }
        }
        System.out.println(count/2);

    }


}

class Pair implements Comparable{
    int start;
    int goal;
    int dir;//0:A, 1:B
    @Override
    public int compareTo(Object other) {
        Pair otherpair = (Pair) other;
        return goal - otherpair.goal;
    }
}