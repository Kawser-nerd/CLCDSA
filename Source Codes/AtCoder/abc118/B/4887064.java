import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(),
            M = sc.nextInt(),
            answer = 0;
        int[] food = new int[M];      
        for(int i = 0; i < N; i++){
            int K = sc.nextInt();
            for(int j = 0; j < K; j++){
                food[sc.nextInt()-1]++;
            }
        }
        for(int i = 0; i < M; i++){
            if(food[i] == N){
                answer++;
            }
        }
        System.out.println(answer);
    }
}