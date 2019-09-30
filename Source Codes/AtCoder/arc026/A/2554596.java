import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int time = 0;
        for(int i=0; i<N; i++){
            if(i<5){
                time = time+B;
            }else{
                time = time+A;
            }
        }
        System.out.println(time);
    }
}