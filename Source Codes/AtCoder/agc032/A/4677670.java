import java.util.*;
import java.io.*;
import static java.lang.System.in;

public class Main {
    static int n,k;
    static long mod = 1000000000+7;
    static long[] fac,inv;
    static int[] id,size;
    //static long mod = 1000000000+7;
    //static HashSet<Integer>[] graph;
    //static ArrayList<Integer>[] graph;
    static ArrayList<Integer> ans = new ArrayList<>();
    static boolean flag = true;
    public static void main(String[] args)throws IOException {
        //BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        //String[] buf = reader.readLine().split(" ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        //int[] b = new int[n+1];
        //for(int i=1;i<=n;i++) b[i]=sc.nextInt();
        // reverse the time line
        ArrayList<Integer> rec = new ArrayList<>();
        for(int i=0;i<n;i++) rec.add(sc.nextInt());
        LinkedList<Integer> ans = new LinkedList<>();
        while(rec.size()>0){
            int idx=-1;
            for(int i=rec.size()-1;i>=0;i--){
                if(rec.get(i)==i+1){
                    idx = i;
                    break;
                }
            }
            if(idx==-1) break;
            ans.addFirst(rec.get(idx));
            rec.remove(idx);
        }
        if(ans.size()!=n) System.out.println(-1);
        else{
            for(int w:ans) System.out.println(w);
        }
    }
}