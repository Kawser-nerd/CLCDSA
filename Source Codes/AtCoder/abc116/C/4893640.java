import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        String[] str = bf.readLine().split(" ");
        int[] h = new int[N];
        for(int i = 0; i < N; i++){
            h[i] = Integer.parseInt(str[i]);
        }
        int answer = h[0];
        for(int i = 0; i < N-1; i++){
            int value = h[i+1] -h[i];
            if(value > 0){
                answer += value;
            }
        }
        System.out.println(answer);
    }
}