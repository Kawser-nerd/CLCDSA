
import java.util.Scanner;
public class bottrust {

	public static void main(String[] args) {
	    Scanner ins = new Scanner(System.in); 

	    int cc;
	    int ntc=ins.nextInt();
	    for (cc=1;cc<=ntc;cc++) {

	    	int pos[]={1,1},time[]={0,0};
		    int cnt=ins.nextInt();
		    for (int i=0;i<cnt;i++) {
		    	String s=ins.next();
		    	int r=0;
		    	if (s.equals("B")) r=1;
			    int p=ins.nextInt();
		    	
			    int mtime=p-pos[r];
			    if (mtime<0) mtime=-mtime;
			    mtime+=time[r]+1;
			    if (mtime<=time[1-r]) mtime=time[1-r]+1;
			    time[r]=mtime;
			    pos[r]=p;			    			    
		    }

		    int maxtime=time[0];
		    if (time[1]>maxtime) maxtime=time[1];
	    	System.out.printf("Case #%d: %d\n",cc,maxtime);
	    }
	}

}
