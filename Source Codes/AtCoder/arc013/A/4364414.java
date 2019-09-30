import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int[] box=new int[3];
        int[] parcel=new int[3];
        for (int i = 0; i < 3; i++) {
            box[i]=sc.nextInt();
        }
        for (int i = 0; i < 3; i++) {
            parcel[i]=sc.nextInt();
        }
        int ans=0;
        for (int i = 0; i < 3; i++) {
            ans=max(ans,(box[0]/parcel[i])*(box[1]/parcel[(i+1)%3])*(box[2]/parcel[(i+2)%3]));
        }
        int t=box[0];
        box[0]=box[1];
        box[1]=t;
        for (int i = 0; i < 3; i++) {
            ans=max(ans,(box[0]/parcel[i])*(box[1]/parcel[(i+1)%3])*(box[2]/parcel[(i+2)%3]));
        }
        out.println(ans);
    }
}