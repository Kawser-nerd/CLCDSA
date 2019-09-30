import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double t = sc.nextDouble();
        double a = sc.nextDouble();
        double height[] = new double[n];
        double min = 1000;
        int index = 0;
        for(int i=0; i<n; i++){
            height[i] = sc.nextDouble();
            double temp = t - height[i]*0.006;
            if(Math.abs(a - temp) < min){
                min = Math.abs(a - temp);
                index = i+1;
            }
        }
        System.out.println(index);
    }
}