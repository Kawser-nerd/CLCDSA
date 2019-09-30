import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

//        int[] a = new int[N];
        SortedSet<Integer> a = new TreeSet<>();
        for (int i = 0; i < N; i++) {
//            a[i] = sc.nextInt();
            a.add(sc.nextInt());
        }







        System.out.println(a.size());
    }
}