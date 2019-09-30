using System;
class Program{
	static int ca1(long[] a,long[] b){
		if((b[0]+b[1]+b[2])>(a[0]+a[1]+a[2])){return 1;}
		else if((b[0]+b[1]+b[2])<(a[0]+a[1]+a[2])){return -1;}
		else{return 0;}
	}
	static int ca2(long[] a,long[] b){
		if((-b[0]+b[1]+b[2])>(-a[0]+a[1]+a[2])){return 1;}
		else if((-b[0]+b[1]+b[2])<(-a[0]+a[1]+a[2])){return -1;}
		else{return 0;}
	}
	static int ca3(long[] a,long[] b){
		if((b[0]-b[1]+b[2])>(a[0]-a[1]+a[2])){return 1;}
		else if((b[0]-b[1]+b[2])<(a[0]-a[1]+a[2])){return -1;}
		else{return 0;}
	}
	static int ca4(long[] a,long[] b){
		if((b[0]+b[1]-b[2])>(a[0]+a[1]-a[2])){return 1;}
		else if((b[0]+b[1]-b[2])<(a[0]+a[1]-a[2])){return -1;}
		else{return 0;}
	}
	static void Main(string[] args){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		long[][] arr=new long[s[0]][];
		long ans=0;
		long c=0;
		
		for(int i=0;i<s[0];i++){
			long[] q=Array.ConvertAll(Console.ReadLine().Split(),long.Parse);
			arr[i] = new long[3];
			for (int j=0;j<3;j++){arr[i][j]=q[j];}
		}

		Array.Sort(arr,ca1);
		for(int i=0;i<s[1];i++){c+=arr[i][0]+arr[i][1]+arr[i][2];}if(ans<c){ans=c;}c=0;
		for(int i=s[0]-1;i>=s[0]-s[1];i--){c+=arr[i][0]+arr[i][1]+arr[i][2];}c=System.Math.Abs(c);if(ans<c){ans=c;}c=0;
		
		Array.Sort(arr,ca2);
		for(int i=0;i<s[1];i++){c+=-arr[i][0]+arr[i][1]+arr[i][2];}if(ans<c){ans=c;}c=0;
		for(int i=s[0]-1;i>=s[0]-s[1];i--){c+=-arr[i][0]+arr[i][1]+arr[i][2];}c=System.Math.Abs(c);if(ans<c){ans=c;}c=0;

		Array.Sort(arr,ca3);
		for(int i=0;i<s[1];i++){c+=arr[i][0]-arr[i][1]+arr[i][2];}if(ans<c){ans=c;}c=0;
		for(int i=s[0]-1;i>=s[0]-s[1];i--){c+=arr[i][0]-arr[i][1]+arr[i][2];}c=System.Math.Abs(c);if(ans<c){ans=c;}c=0;

		Array.Sort(arr,ca4);
		for(int i=0;i<s[1];i++){c+=arr[i][0]+arr[i][1]-arr[i][2];}if(ans<c){ans=c;}c=0;
		for(int i=s[0]-1;i>=s[0]-s[1];i--){c+=arr[i][0]+arr[i][1]-arr[i][2];}c=System.Math.Abs(c);if(ans<c){ans=c;}c=0;
		
		Console.WriteLine(ans);
		
	}
}