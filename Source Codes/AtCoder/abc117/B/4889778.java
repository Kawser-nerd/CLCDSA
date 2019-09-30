import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader bf = 
            new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        String[] str = bf.readLine().split(" ");
        int max = 0,
            sum = 0;
        for(int i = 0; i < N; i++){
            int value = Integer.parseInt(str[i]);
            sum += value;
            if(max < value){
                max = value;
            }
        }
        if(sum - max > max){
            System.out.println("Yes");
        } else{
            System.out.println("No");
        }        
    }
}