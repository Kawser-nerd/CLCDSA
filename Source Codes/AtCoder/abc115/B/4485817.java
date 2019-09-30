import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int array[] = new int[n];
        int sum = 0;
        int max = 0;
        for(int i=0; i<n; i++){
            array[i] = sc.nextInt();
            sum += array[i];
            if(max < array[i]){
                max = array[i];
            }
        }
        sum = sum - max/2;
        System.out.println(sum);
    }
}