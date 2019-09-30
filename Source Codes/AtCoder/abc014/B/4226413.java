import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int x=sc.nextInt();
        int [] nums=new int[n];
        int output=0;
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            if(x%Math.pow(2,i+1)-x%Math.pow(2,i)!=0){
                output+=nums[i];
            }
        }
        System.out.println(output);
        
        

    }

}