import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int sec = 101;

        for(int i = 0; i < n; i++){
           sec = Math.min(sc.nextInt(),sec);
        }
        System.out.println(sec);
    }
}