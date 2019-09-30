import java.util.Arrays;
import java.util.Collection;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt(),sum=0;
        for(int i=1;i<=N;i++){
            sum+=i;
        }
        System.out.println((sum*10000)/N);
    }


    static String adjustValue(int value) {
        if (10 > value) {
            return "0" + value;
        } else {
            return value + "";
        }
    }
}