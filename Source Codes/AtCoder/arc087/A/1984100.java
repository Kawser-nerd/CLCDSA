import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String []args){
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        ArrayList<Integer>al=new ArrayList<>();
        long ans=0;
        int count[]=new int[(int)1e5+1];
        for (int i = 0; i <n; i++) {
            int a =in.nextInt();
            if(a>n){
                ans++;
            }else{
                al.add(a);
                count[a]++;
            }
        }
        for (int i = 0; i <al.size(); i++){
            if(count[al.get(i)]!=al.get(i)){
                count[al.get(i)]--;
                ans++;
            }
        }
        System.out.println(ans);

    }
}