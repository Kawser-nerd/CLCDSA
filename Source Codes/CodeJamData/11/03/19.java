import java.util.Scanner;
public class candy {

	public static void main(String[] args) {
	    Scanner ins = new Scanner(System.in); 

	    int cc;
	    int ntc=ins.nextInt();
	    for (cc=1;cc<=ntc;cc++) {

		    int nc=ins.nextInt();
		    int sum=0,sxor=0,min=1000000000;
		    for (int i=0;i<nc;i++) {
			    int c=ins.nextInt();
			    sum+=c;
			    sxor^=c;
			    if (c<min) min=c;
		    }
		    
		    if (sxor==0) System.out.printf("Case #%d: %d\n",cc,sum-min);
		    else System.out.printf("Case #%d: NO\n",cc);
	    }
	}

}
