import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int hana[] = new int[n];
        int count = 0;

        for(int i=0; i<n; i++){
            hana[i] = sc.nextInt();
        }

        for(int i=0; i<n; i++){
            int m = hana[i];
            if(m%6 == 0) count += 3;
            if(m%6 == 2) count += 1;
            if(m%6 == 4) count += 1;
            if(m%6 == 5) count += 2;
        }
        System.out.println(count);
    }
}