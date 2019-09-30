using System;
class Program{
	static int s;
	static long[][] arr;
	static void Main(){
		s=int.Parse(Console.ReadLine());
		arr=new long[s][];
		long th=100010000000000,tl=0,tc=th>>1;

		for(int i=0;i<s;i++){
			arr[i]=Array.ConvertAll((Console.ReadLine()+" 0").Split(),long.Parse);
			arr[i][2]=(tc-arr[i][0])/arr[i][1];
		}

		Array.Sort(arr,ca);

		bool b;
		b=true;
		for(int i=0;i<s;i++){
			if(arr[i][2]<i){b=false;break;}
		}

		if(b){th=tc;}
		else{tl=tc+1;}
		tc=(th+tl)/2;

		while(th!=tl){
			b=true;
			for(int i=0;i<s;i++){
				if(tc<arr[i][0]){b=false;break;}
				arr[i][2]=(tc-arr[i][0])/arr[i][1];
			}
			if(b){
				Array.Sort(arr,ca);
				for(int i=0;i<s;i++){if(arr[i][2]<i){b=false;break;}}
			}

			if(b){th=tc;}
			else{tl=tc+1;}
			tc=(th+tl)/2;
		}
		
		Console.WriteLine(th);
	}
	static int ca(long[] a,long[] b){
		if(a[2]<b[2]){return -1;}
		else if(a[2]>b[2]){return 1;}
		else{return 0;}
	}
}