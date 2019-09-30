import java.util.*;

public class C
{
    public static int front;

    public static int rotate(int in)
    {
	return (in / 10) + front*(in % 10);
    }

    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);

	int T = in.nextInt();

	for(int c = 1; c <= T; c++){
	    int ans = 0;

	    int A = in.nextInt();
	    int B = in.nextInt();

	    int ndig = ("" + A).length();
	    front = 1;
	    for(int i = 1; i < ndig; i++)
		front *= 10;
	    
	    for(int num = A; num <= B; num++){
		int count = 1;
		int rot = rotate(num);
		boolean smallest=true;
		while(smallest &&  rot!= num){
		    if(A <= rot && rot <= B)
			if(rot < num)
			    smallest = false;
			else
			    count++;
		    rot = rotate(rot);
		}
		if(smallest)
		    ans += count*(count - 1)/2;
	    }	

	    System.out.println("Case #" + c + ": " + ans);
	}



    }


}