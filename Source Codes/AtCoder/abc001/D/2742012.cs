using System;
class Program{
	static void Main(){
		int s=int.Parse(Console.ReadLine());
		int[][] arr=new int[s][];

		for (int i=0;i<s;i++){
			arr[i]=Array.ConvertAll(Console.ReadLine().Split('-'),int.Parse);
			arr[i][0]-=arr[i][0]%5;
			arr[i][1]+=(5-(arr[i][1]%5))%5;
			if(arr[i][1]%100==60){arr[i][1]+=40;}
		}
		Array.Sort(arr,ca);
		
		for (int i=0;i<s-1;i++){
			if(arr[i][1]>=arr[i+1][0]){
				arr[i+1][0]=arr[i][0];
				arr[i+1][1]=Math.Max(arr[i][1],arr[i+1][1]);
				arr[i][0]=9999;
			}
		}
		string b="",c="";
		for (int i=0;i<s;i++){
			if(arr[i][0]!=9999){
				b=arr[i][0].ToString();
				c=arr[i][1].ToString();
				while(b.Length<4){b="0"+b;}
				while(c.Length<4){c="0"+c;}
				Console.WriteLine("{0}-{1}",b,c);
			}
		}
	}
	static int ca(int[] a,int[] b){
		if(a[0]>b[0]){return 1;}
		else if(a[0]<b[0]){return -1;}
		else{
			if(a[1]>b[1]){return 1;}
			else if(a[1]<b[1]){return -1;}
			return 0;
		}
	}
}