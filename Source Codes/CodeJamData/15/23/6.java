import java.util.*;
public class Herb {
    static int val() {
        int groups = sc.nextInt();
        long[] start = new long[groups];
        long[] size = new long[groups];
        long[] period = new long[groups];
        int total = 0;
        for (int i=0; i<groups; i++) {
            start[i] = sc.nextInt();
            size[i] = sc.nextInt();
            total += size[i];
            period[i] = sc.nextInt();
        }
        long[] first = new long[total];
        long[] diff = new long[total];
        {        int j = 0;
        for (int i=0; i<groups; i++) {
            for (int k=0; k<size[i]; k++) {
                first[j] = (period[i]+k)*2*(360-start[i]);
                diff[j] = 2*360*period[i];
                j++;
            }            
        }
        //System.out.println(j+" "+total); 
        }
        long opt = total+1;
        for (int i=0; i<total; i++) {
            long crossings = 0;
            for (int j=0; j<total; j++) {
                if (first[i]+1 <= first[j]) crossings += 1;
                else if (first[i]+1 <= first[j]+diff[j]) crossings += 0;
                else crossings += (first[i]+1 - first[j])/diff[j];
            }
            opt = Math.min(opt, crossings);
        }
        return (int) opt;
    }
    
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int k = sc.nextInt();
        for (int kk=1; kk<=k; kk++) 
            System.out.println("Case #"+kk+": "+val());
    }
}