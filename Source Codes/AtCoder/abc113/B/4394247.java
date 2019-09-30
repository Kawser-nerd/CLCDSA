import java.io.*;
import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double T = scanner.nextDouble();
        int A = scanner.nextInt();
        double H[] = new double[N];
        double tmp[] = new double[N];
        for(int i=0;i<N;i++){
            H[i] = scanner.nextDouble();
            tmp[i] = Math.abs(A-(T-H[i]*0.006));
        }
        double min = tmp[0];
        int imin =1;
        for(int i=0;i<N;i++){
            if(min>=tmp[i]){
                min = tmp[i];
                imin = i+1;
            }
        }

        System.out.println(imin);
        
        scanner.close();
           }

}