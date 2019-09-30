import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] ar = s.split("");
        int n = sc.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0 ; i < n ; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        for (int i = 0 ; i < n ; i++) {
            String[] temp = ar;
            List<String> list = new ArrayList<>();
            for (int j = l[i] - 1; j < r[i] ; j++) {
                list.add(ar[j]);
            }
            Collections.reverse(list);
            for (int j = l[i] - 1 ; j < r[i] ; j++) {
                ar[j] = list.get(j - l[i] + 1);
            }
        }
        System.out.println(String.join("", ar));
 
    }
 
}