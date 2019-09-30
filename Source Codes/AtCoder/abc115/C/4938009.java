import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        String[] str = bf.readLine().split(" ");
        int N = Integer.parseInt(str[0]),
            K = Integer.parseInt(str[1]);
        int[] h = new int[N];
        for(int i = 0; i < N; i++){
            h[i] = Integer.parseInt(bf.readLine());
        }
        Arrays.sort(h);
        int min = h[N-1] - h[0];
        for(int i = 0; i < N-K+1; i++){
            int value = h[i+K-1] - h[i];
            if(value < min){
                min = value;
            }
        }
        System.out.println(min);
    }
}