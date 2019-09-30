import java.util.*;

public class D
{
    public static boolean wall[][];
    public static int X;
    public static int Y;
    
    public static int[] dxs;
    public static int[] dys;

    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

	for(int c = 1; c <= T; c++){
	    int H = in.nextInt();
	    int W = in.nextInt();
	    int D = in.nextInt();

	    dxs = new int[4];
	    dys = new int[4];
	    
	    dxs[0] = dxs[1] =  1;
	    dxs[2] = dxs[3] = -1;
	    dys[0] = dys[2] =  1;
	    dys[1] = dys[3] = -1;
	    
	    wall = new boolean[H][W];
	    
	    int mex, mey;
	    mex = 0;
	    mey = 0;
	    
	    in.nextLine();
	    for(int i = 0; i < H; i++){
		String line = in.nextLine();
		for(int j = 0; j < W; j++){
		    switch( line.charAt(j)){
		    case '#':
			wall[i][j] = true;
			break;
		    case 'X':
			mex = j;
			mey = i;
		    case '.':
			wall[i][j] = false;
			break;
		    }
		}
	    }//done reading input.
	    
	    int count = 0;

	    //check NESW
	    int nd = 1, ed = 1, sd = 1, wd = 1;
	    while(!wall[mey][mex+ed]) ed++;
	    while(!wall[mey][mex-wd]) wd++;
	    while(!wall[mey+nd][mex]) nd++;
	    while(!wall[mey-sd][mex]) sd++;

	    if(2*ed-1 <= D) count++;
	    if(2*wd-1 <= D) count++;
	    if(2*sd-1 <= D) count++;
	    if(2*nd-1 <= D) count++;

	    for(int x = 1; x <= D; x++)
		for(int y = 1; y <= D; y++){
		    if(x*x + y*y > D*D)
			continue;
		    
		
		    for(int d = 0; d < 4; d++){
			
			int posx = mex;
			int posy = mey;
			int dx = dxs[d];
			int dy = dys[d];

			boolean fail = false;

			int distx = 0;
			int disty = 0;
			
			

			for(int s = 1; s <= 2*x*y && !fail; s++){
			    distx += dx;
			    disty += dy;
			    
			    //System.out.println("distx = " + distx +"; disty = " + disty);

			    if(s < 2*x*y && distx == 0 && disty == 0)
				fail = true;
			    
			    if((s % x == 0) && ( (s/x) % 2 == 1) 
			       && (s % y == 0) && ( (s/y) % 2 == 1)){
				if(!wall[posy + dy][posx + dx]){
				    posy += dy;
				    posx += dx;
				}else if(wall[posy][posx + dx] && wall[posy + dy][posx]){
				    dx *= -1;
				    dy *= -1;
				}
				else if(wall[posy][posx + dx]){
				    dx *= -1;
				    posy += dy;
				}
				else if(wall[posy + dy][posx]){
				    posx += dx;
				    dy *= -1;
				}
				else{
				    fail = true;
				}
			    }
			    else if((s % x == 0) && ( (s/x) % 2 == 1)){ 
				if(wall[posy][posx + dx])
				    dx *= -1;
				else
				    posx += dx;
			    }
			    else if((s % y == 0) && ( (s/y) % 2 == 1)){
				if(wall[posy + dy][posx])
				    dy *= -1;
				else
				    posy += dy;
			    }
			}

			if(!fail && posx == mex && posy == mey){
			    //System.out.println("x = " + x +"; y = " + y);
			    count++;
			}
		    }
		}
	    System.out.println("Case #" + c +": " + count);
	}
    }
}