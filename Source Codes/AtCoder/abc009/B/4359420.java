import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int n_max = 0, n_submax = 0;
        for(int i = 0; i < n; i++){
            int k = scan.nextInt();
            if(k > n_max){
                n_submax = n_max;
                n_max = k;
            }else if(k < n_max && k > n_submax){
                n_submax = k;
            }
            //System.out.println("i = " + i + ": n_max = " + n_max + ", n_submax = " + n_submax);
        }
        System.out.println(n_submax);
    }
}