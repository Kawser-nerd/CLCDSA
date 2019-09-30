using System;
class Program{
	static void Main(){
		double[] s=Array.ConvertAll(Console.ReadLine().Split('/'),double.Parse);
		while(s[0]/s[1]/s[2]!=(int)(s[0]/s[1]/s[2])){
			if(s[1]==12&&s[2]==31){s[0]++;s[1]=1;s[2]=1;}
			else if(s[2]==31){s[1]++;s[2]=1;}
			else if(s[2]==30&&(s[1]==4||s[1]==6||s[1]==9||s[1]==11)){s[1]++;s[2]=1;}
			else if(s[1]==2&&s[2]==29){s[1]++;s[2]=1;}
			else if(s[1]==2&&s[2]==28){
				if(s[0]%400==0){s[2]++;}
				else if(s[0]%100==0){s[1]++;s[2]=1;}
				else if(s[0]%4==0){s[2]++;}
				else{s[1]++;s[2]=1;}
			}
			else{s[2]++;;}
		}
		Console.WriteLine("{0}/{1}{2}/{3}{4}",s[0],new string('0',2-s[1].ToString().Length),s[1],new string('0',2-s[2].ToString().Length),s[2]);
	}
}