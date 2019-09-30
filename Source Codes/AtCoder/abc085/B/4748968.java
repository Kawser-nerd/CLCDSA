import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());

        int d[] = new int[n];
        for(int i = 0; i < n; i++){
            d[i] = Integer.parseInt(sc.next());
        }

        int num[] = new int [101];
        for(int i = 0; i < n; i++){
            num[d[i]]++;
        }

        int cnt = 0;
        for (int i = 0; i < 101; i++) {
            if(num[i] > 0){
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}