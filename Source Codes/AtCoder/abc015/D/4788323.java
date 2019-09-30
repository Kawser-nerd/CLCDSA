import java.util.*;
class ScreenShot {
    int index;
    int width;
    int value;

    public ScreenShot (int index, int width, int value) {
	this.index = index;
	this.width = width;
	this.value = value;
    }
}
class Main {
    static int W;
    static int N;
    static int K;
    static ScreenShot[] ss;
    static int[][][] totalVal;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	W = sc.nextInt();
	N = sc.nextInt();
	K = sc.nextInt();
	ss = new ScreenShot[N+1];
	totalVal = new int[N+1][W+1][K+1];
	for(int i = 0; i<=N; i++) {
	    for(int j = 0; j<=W; j++) {
		for(int l = 0; l<=K; l++) {
		    totalVal[i][j][l] = -1;
		}
	    }
	}
	for(int i = 1; i<=N; i++) {
	    ss[i] = new ScreenShot(i, sc.nextInt(), sc.nextInt());
	}
	System.out.println(dfs(N,W,K));
    }

    public static int dfs(int depth, int totalWidth, int totalNum) {
	if(totalWidth > W || totalWidth<=0) return 0;
	if(totalNum > K || totalNum<=0) return 0;
	if(depth<=0) return 0;

	int a = 0;
	int b = 0;
	if(totalWidth-ss[depth].width>=0 && depth-1>=0 && totalNum-1 >=0 && totalVal[depth-1][totalWidth-ss[depth].width][totalNum-1]==-1)
	    totalVal[depth-1][totalWidth-ss[depth].width][totalNum-1] = dfs(depth-1, totalWidth-ss[depth].width, totalNum-1);
	if(totalWidth-ss[depth].width>=0 && depth-1>=0 && totalNum-1 >=0)
	    a = totalVal[depth-1][totalWidth-ss[depth].width][totalNum-1] + ss[depth].value;
	else
	    a = (ss[depth].width<=totalWidth)?ss[depth].value:0;
	if(depth-1>=0 && totalVal[depth-1][totalWidth][totalNum]==-1)
	    totalVal[depth-1][totalWidth][totalNum] = dfs(depth-1, totalWidth, totalNum);
	if(depth-1>=0)
	    b = totalVal[depth-1][totalWidth][totalNum];

	totalVal[depth][totalWidth][totalNum] =  Math.max(a , b);
	//	System.out.println("d " + depth + " tw " + totalWidth + " tn " + totalNum + " a " + a + " b " + b);
	return totalVal[depth][totalWidth][totalNum];
    }

}