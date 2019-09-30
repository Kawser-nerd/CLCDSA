import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[] a = {1,3,5,7,8,10,12};
        int[] b = {4,6,9,11};
        
        if(x==2 || y==2){
            System.out.println("No");
            return;
        }
        for(int i = 0; i < a.length; i++){
            if(x==a[i]){
                for(int j = 0; j < a.length; j++){
                    if(y==a[j]){
                        System.out.println("Yes");
                        return;
                    }
                }
            }
        }
        for(int i = 0; i < b.length; i++){
            if(x==b[i]){
                for(int j = 0; j < b.length; j++){
                    if(y==b[j]){
                        System.out.println("Yes");
                        return;
                    }
                }
            }
        }
        System.out.println("No");
    }
}