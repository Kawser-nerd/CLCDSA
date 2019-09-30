import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Integer[] l = new Integer[n];
        int sum = 0;
        for(int i=0; i<n; i++){
            l[i] = sc.nextInt();
        }
        
        Arrays.sort(l,Comparator.reverseOrder());
        for(int i=0; i<k; i++){
            sum += l[i];
        }
        System.out.println(sum);
    }
}