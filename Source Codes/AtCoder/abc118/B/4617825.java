import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        ArrayList<Integer>[] list = new ArrayList[N];
        for (int i=0; i<N; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i=0; i<N; i++) {
            int S = sc.nextInt();
            for (int j=0; j<S; j++) {
                list[i].add(sc.nextInt());
            }
        }
        int counter = 0;
        for (int i=0; i<=M; i++) {
            boolean flag = true;
            for (int j=0; j<N; j++) {
                if (list[j].contains(i)) {
                } else {
                    flag = false;
                }
            }
            if (flag) {
                counter++;
            }
        }
        System.out.println(counter);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.