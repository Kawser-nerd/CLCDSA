import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int array[] = new int[n];
        for(int i=0; i<n; i++){
            array[i] = sc.nextInt();
        }
        Arrays.sort(array);
        int min = array[n-1];
        for(int i=0; i<=n-k; i++){
            if(min > array[i+k-1] - array[i]) min = array[i+k-1] - array[i];
        }
        System.out.println(min);
    }
}