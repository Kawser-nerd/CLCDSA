import java.util.*;
 
public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int price[] = new int[n];
 
        for(int i=0; i<n ; i++){
            price[i] = sc.nextInt();
        }
 
        Arrays.sort(price);
 
        for(int k=n-1; k>0; k--){
            if(price[k] > price[k-1]){
                System.out.println(price[k-1]);
                break;
            }
        }
    }
}