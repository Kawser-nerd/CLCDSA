import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        
        int a[] = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(sc.next());
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i] - 1;
        }

        System.out.println(sum);
        
        sc.close();
    }
}