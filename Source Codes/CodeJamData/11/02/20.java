
import java.util.Scanner;
public class magicka {

	public static void main(String[] args) {
	    Scanner ins = new Scanner(System.in); 

	    int cc;
	    int ntc=ins.nextInt();
	    for (cc=1;cc<=ntc;cc++) {
	    	byte comb[][]=new byte[256][256];
	    	boolean opp[][]=new boolean[256][256];
	    	int ncomb=ins.nextInt();
	    	for (int i=0;i<ncomb;i++) {
	    		byte[] b=ins.next().getBytes();
	    		comb[b[0]][b[1]]=b[2];	    		
	    		comb[b[1]][b[0]]=b[2];	    		
	    	}
	    	int nopp=ins.nextInt();
	    	for (int i=0;i<nopp;i++) {
	    		byte[] b=ins.next().getBytes();
	    		opp[b[0]][b[1]]=true;	    		
	    		opp[b[1]][b[0]]=true;	    		
	    	}
	    	
	    	int ilen=ins.nextInt();
	    	byte[] b=ins.next().getBytes();
	    	byte[] res=new byte[ilen];
	    	int len=0;
	    	for (int i=0;i<ilen;i++) {
	    		res[len++]=b[i];
	    		byte c=1;
	    		while ((len>=2) && (c!=0)) {
	    			c=comb[res[len-2]][res[len-1]];
	    			if (c!=0) {
	    				len--;
	    				res[len-1]=c;
	    			}
	    		}
	    		if (len>=2) {
	    			for (int j=0;j<len-1;j++)
	    				if (opp[res[j]][res[len-1]]) len=0;
	    		}
	    	}
	    	
	    	String rs="";
	    	for (int i=0;i<len;i++) {
	    		if (i>0) rs=rs+", ";
	    		rs=rs+(char)res[i];
	    	}
	    	System.out.printf("Case #%d: [%s]\n",cc,rs);
	    }
	}

}
