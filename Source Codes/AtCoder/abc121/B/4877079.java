import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(),
            M = sc.nextInt(),
            C = sc.nextInt(),
            correct = 0;
        int[] B = new int[M];
        for(int i = 0; i < M; i++){
            B[i] = sc.nextInt();
        }
        for(int i = 0; i < N; i++){
            int value = C;
            for(int j = 0; j < M; j++){
                value += sc.nextInt()*B[j];
            }
            if(value > 0){
                correct++;
            }
        }
        System.out.println(correct);
    }
}