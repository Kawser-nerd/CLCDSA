import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        boolean[] visit = new boolean[n];

        int current = 0;
        int count = 0;

        visit[1] = true;

        //??????
        while (true) {
            current = array[current] - 1;
            count++;
            if (current == 1) {
                System.out.println(count);
                return;
            }
            if (visit[current]) {
                System.out.println("-1");
                return;
            }
            visit[current] = true;
        }
    }

}