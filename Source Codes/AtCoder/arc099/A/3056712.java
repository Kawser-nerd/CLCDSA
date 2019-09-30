import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pos1 = 0;
        int n = sc.nextInt();
        int k = sc.nextInt();
        for(int i=0; i<n; i++){
            int tmp = sc.nextInt();
            if(tmp == 1) pos1 = i;
        }

        if((n-k)%(k-1) == 0){
            System.out.println((n-k)/(k-1) + 1);
        }else{
            System.out.println((n-k)/(k-1) + 2);
        }
    }
}