using System;
class Program{
	static int km=0;
	static int k1=0,r1=1<<29,r2=0;
	static int[] s;
	static int[,] ha,kr;
	static string[] arr;
	static void Main(){
		s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		arr=new string[s[0]];
		ha=new int[s[0],s[1]];
		kr=new int[s[0],s[1]];
		int sh=-1,sw=-1,gh=-1,gw=-1,p=1,q=1;
		for(int i=0;i<s[0];i++){
			arr[i]=Console.ReadLine();
			for(int j=0;j<s[1];j++){
				ha[i,j]=99;
				kr[i,j]=99;
				if(arr[i][j].ToString()=="S"){sh=i;sw=j;}
				else if(arr[i][j].ToString()=="G"){gh=i;gw=j;}
			}
		}

		while(k1==0){
			for(int i=0;i<s[0];i++){
				for(int j=0;j<s[1];j++){ha[i,j]=99;kr[i,j]=99;}
			}
			fu(sh,sw,0,0);
			km++;
		}
		ha=new int[s[0],s[1]];

		if(sh>gh){p=-1;}
		if(sw>gw){q=-1;}
		for(int i=sh;ha[gh,gw]==0;i+=p){
			for(int j=sw;j!=gw+q;j+=q){
				if(arr[i][j].ToString()=="#"){ha[i,j]=1;}
				if(i==sh&&j==sw){}
				else if(i==sh){ha[i,j]+=ha[i,j-q];}
				else if(j==sw){ha[i,j]+=ha[i-p,j];}
				else{ha[i,j]+=Math.Min(ha[i-p,j],ha[i,j-q]);}
			}
		}
		
		r2=Math.Abs(sh-gh)+Math.Abs(sw-gw);
		Console.WriteLine(Math.Max((s[2]-(r1-k1))/k1,(s[2]-(r2-ha[gh,gw]))/ha[gh,gw]));
	}
	static void fu(int a,int b,int k,int r){
		if(arr[a][b].ToString()=="G"){k1=km;r1=Math.Min(r1,r);}
		else if(arr[a][b].ToString()=="#"){k++;}
		if(k<=km&&(ha[a,b]>k||(ha[a,b]>=k&&kr[a,b]>r))){
			ha[a,b]=k;
			kr[a,b]=r;
			if(a>0){fu(a-1,b,k,r+1);}
			if(a<s[0]-1){fu(a+1,b,k,r+1);}
			if(b>0){fu(a,b-1,k,r+1);}
			if(b<s[1]-1){fu(a,b+1,k,r+1);}
		}
	}
}