import java.util.*;
public class Main{
    public static void main(String[]$){
        Scanner c=new Scanner(System.in);
        int n=c.nextInt();
        int[] a=new int[n];
        TreeSet<Integer> s=new TreeSet<>();
        for(int i=0;i<n;i++){
            a[i]=c.nextInt();
            s.add(a[i]);
        }
        Map<Integer,Integer> m=new HashMap<>();
        int t=s.size();
        for(int i=0;i<t;i++){m.put(s.pollFirst(),i);}
        for(int i=0;i<n;i++){System.out.println(m.get(a[i]));}
    }
}