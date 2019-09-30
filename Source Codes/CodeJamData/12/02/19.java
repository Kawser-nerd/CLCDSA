import java.util.*;

public class B
{
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for(int c = 1; c <= T; c++){
	    int n = in.nextInt();
	    int s = in.nextInt();
	    int p = in.nextInt();
	    
	    int high = 0;
	    int low = 0;
	    
	    int ans;

	    if(p < 2){
		int count = 0;
		for(int i = 0; i < n; i++){
		    int t = in.nextInt();
		    if(t > 0) count++;
		}
		if(p == 0)
		    ans = n;
		else
		    ans = count;
	    }
	    else{
		for(int i = 0; i < n; i++){
		    int t = in.nextInt();
		    if(t >= 3*p - 2)
			high++;
		    else if(t >= 3*p - 4)
			low++;
		}
		
		 ans = ans = high + ((s < low)? s : low);
	    }
	    System.out.println("Case #" + c + ": " + ans);
	    
	}

    }

}