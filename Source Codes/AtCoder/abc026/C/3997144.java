import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] b = new int[n];
        for (int i = 1 ; i < n ; i++) {
            b[i] = sc.nextInt();
        }
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0 ; i < n ; i++) {
            List<Integer> subList = new ArrayList<>();
            for (int j = 0 ; j < n ; j++) {
                if (i + 1 == b[j]) {
                    subList.add(j);
                }
            }
            list.add(subList);
        }

        int[] p = new int[n];
        for (int i = n - 1 ; i >= 0; i--) {
            if (list.get(i).size()== 0) {
                p[i] = 1;
            } else {
                int min = (int) 1e9;
                int max = 0;
                for (int j = 0 ; j < list.get(i).size(); j++) {
                    min = Math.min(min, p[list.get(i).get(j)]);
                    max = Math.max(max, p[list.get(i).get(j)]);
                }
                p[i] = min + max + 1;
            }
        }
        System.out.println(p[0]);


    }

}