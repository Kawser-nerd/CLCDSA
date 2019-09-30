import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double[] x = new double[N];
        String[] u = new String[N];
        double sum = 0;
        for(int i = 0; i < N; i++){
            x[i] = sc.nextDouble();
            u[i] = sc.next();
        }
        for(int i = 0; i < N; i++){
            if(u[i].equals("BTC")){
                sum += x[i]*380000;
            } else {
                sum += x[i];
            }
        }        
        System.out.println(sum);
    }
}