using System;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int n=int.Parse(Console.ReadLine());
		int[][] arr=new int[n][];
		int i;
		int ans=0;
		for (i=0;i<n;i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			if(i>0){
				if(fu(s[0],s[1],s[2],s[3],arr[i][0],arr[i][1],arr[i-1][0],arr[i-1][1])==true){ans++;}
			}
		}
		if(fu(s[0],s[1],s[2],s[3],arr[0][0],arr[0][1],arr[i-1][0],arr[i-1][1])==true){ans++;}
		Console.WriteLine(ans/2+1);
	}
	static bool fu(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
		double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
		double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
		double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
		double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
		return tc*td<0&&ta*tb<0;
	}
}