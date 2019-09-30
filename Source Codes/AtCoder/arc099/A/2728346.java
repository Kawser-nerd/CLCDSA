import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < n; i++) {
            sc.nextInt();
        }
        int i = 1;
        int tmp = m - 1;
        while (m < n) {
            i++;
            m += tmp;
        }
        System.out.println(i);
    }
}