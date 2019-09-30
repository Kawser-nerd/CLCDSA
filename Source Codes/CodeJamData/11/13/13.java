import java.util.Scanner;

public class cards {

	public static void main(String[] args) {
	    Scanner ins = new Scanner(System.in); 

	    int cc;
	    int ntc=ins.nextInt();
	    for (cc=1;cc<=ntc;cc++) {

	    	int[] c=new int[80];
	    	int[] s=new int[80];
	    	int[] t=new int[80];
	    	
	    	int n=ins.nextInt();
	    	for (int i=0;i<n;i++) {
	    		c[i]=ins.nextInt();
	    		s[i]=ins.nextInt();
	    		t[i]=ins.nextInt();
	    	}
	    	int m=ins.nextInt();
	    	for (int i=n;i<n+m;i++) {
	    		c[i]=ins.nextInt();
	    		s[i]=ins.nextInt();
	    		t[i]=ins.nextInt();
	    	}
	    	
	    	int mscore=0;
	    	for (int cmax=n;cmax<=n+m;cmax++) {
	    		
	    		int hand=n;
	    		int turns=1;
	    		int score=0;
	    		boolean[] played = new boolean[80];
	    		boolean cont=true;
	    		while ((turns>0) && cont) {
	    			cont=false;
	    			for (int i=0;i<hand;i++)
	    				if ((!played[i]) && (t[i]>0)) {
	    					played[i]=true;
	    					cont=true;
	    					hand+=c[i];
	    					if (hand>n+m) hand=n+m;
	    					score+=s[i];
	    					turns+=t[i]-1;
	    				}
	    			int msc=-1;
	    			int msi=-1;
	    			for (int i=0;i<hand;i++)
	    				if ((!played[i]) && (s[i]>msc) && ((c[i]>0)||(hand>=cmax))) {
	    					msi=i;
	    					msc=s[i];
	    				}
	    			if (msi>=0) {
						played[msi]=true;
    					cont=true;
						hand+=c[msi];
    					if (hand>n+m) hand=n+m;
						score+=s[msi];
						turns+=t[msi]-1;
	    			}
	    		}
	    		if (score>mscore) mscore=score;
	    	}
	    		
	    	System.out.printf("Case #%d: %d\n",cc,mscore);
	    }
	}

}
