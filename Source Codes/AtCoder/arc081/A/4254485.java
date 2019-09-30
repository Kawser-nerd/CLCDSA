/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        long[] a=new long[n];
        long edge1=0,edge2=0;
        TreeMap<Long,Long> tm=new TreeMap<>();
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
            tm.put(a[i],tm.getOrDefault(a[i],0l)+1);
        }
        while (tm.size()>0&&edge1==0){
            Map.Entry<Long,Long> temp=tm.pollLastEntry();
            if(temp.getValue()>1){
                edge1=temp.getKey();
                tm.put(temp.getKey(),temp.getValue()-2);
            }
        }
        while (tm.size()>0&&edge2==0){
            Map.Entry<Long,Long> temp=tm.pollLastEntry();
            if(temp.getValue()>1){
                edge2=temp.getKey();
            }
        }
        out.println(edge1*edge2);
    }
}