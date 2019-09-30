import java.io.*;
import java.util.Arrays;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        String[] str = bf.readLine().split(" ");
        int N = Integer.parseInt(str[0]),
            M = Integer.parseInt(str[1]);
        if(N >= M){
            System.out.println("0");
            return;
        }
        int[] X = new int[M];
        str = bf.readLine().split(" ");
        for(int i = 0; i < M; i++){
            X[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(X);
        int[] L = new int[M-1];
        for(int i = 0; i < M-1; i++){
            L[i] = X[i+1] - X[i];
        }
        Arrays.sort(L);
        int sumL = 0;
        for(int i = 0; i < N-1; i++){
            sumL += L[M-i-2];
        }
        System.out.println(X[M-1]-X[0]-sumL);
    }
}