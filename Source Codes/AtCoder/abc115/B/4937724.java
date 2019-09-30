import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine()),
            max = 0,
            sum = 0;
        int[] p = new int[N];
        for(int i = 0; i < N; i++){
            p[i] = Integer.parseInt(bf.readLine());            
            sum += p[i]; 
            if(max < p[i]){
                max = p[i];
            }
        }
        sum -= max/2;        
        System.out.println(sum);
    }
}