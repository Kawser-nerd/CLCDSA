import java.util.Scanner;
public class goro {

	public static void main(String[] args) {
	    Scanner ins = new Scanner(System.in); 

	    int cc;
	    int ntc=ins.nextInt();
	    for (cc=1;cc<=ntc;cc++) {
		    int len=ins.nextInt();
		    int[] arr=new int[len];
		    int[] coll=new int[len];
		    for (int i=0;i<len;i++) {
		    	int v=ins.nextInt()-1;
		    	arr[i]=v;
		    }
		    int cnt=0;
		    for (int i=0;i<len;i++) {
		    	if (arr[i]!=i) {
		    		int j=arr[i];
		    		int ccnt=1;
		    		coll[0]=i;
		    		while (j!=i) {
		    			coll[ccnt]=j;
		    			j=arr[j];
		    			ccnt++;
		    		}
		    		for (int k=0;k<ccnt;k++) arr[coll[k]]=coll[k];
		    		cnt+=ccnt;
		    	}
		    }
		    
	    	System.out.printf("Case #%d: %d.000000\n",cc,cnt);
	    }
	}

}
