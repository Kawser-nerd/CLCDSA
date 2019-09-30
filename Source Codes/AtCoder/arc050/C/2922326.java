import java.util.*;
class Main{
  
  static long gcd(long a, long b){
    if(b==0)return a;
    return gcd(b, a%b);
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long a =sc.nextLong();
    long b = sc.nextLong();
    long mod = sc.nextLong();
    if(b>a){long tmp=a;a=b;b=tmp;}
    long g = gcd(a,b);
    long tengcd = 1;
    long ten = 10%mod;
    for(int i=0;i<64;++i){
      if(((g>>i)&1)==1)tengcd=(tengcd*ten)%mod;
      ten=(ten*ten)%mod;
    }
    long[] bekione = new long[64];
    long[] bekiten = new long[64];
    bekione[0] = 1;
    bekiten[0] = 10%mod;
    for(int i=1;i<64;++i){
      bekiten[i] = bekiten[i-1]*bekiten[i-1]%mod;
      bekione[i] = (bekione[i-1]*bekiten[i-1]%mod + bekione[i-1])%mod;
    }
    long onea = 0;
    for(int i=0;i<64;++i){
      if(((a>>i)&1)==1)onea = (onea*bekiten[i]%mod +bekione[i])%mod;
    }
    
    long[] bekione2 = new long[64];
    long[] bekiten2 = new long[64];
    bekione2[0] = 1;
    bekiten2[0] = tengcd;
    for(int i=1;i<64;++i){
      bekiten2[i] = bekiten2[i-1]*bekiten2[i-1]%mod;
      bekione2[i] = (bekione2[i-1]*bekiten2[i-1]%mod + bekione2[i-1])%mod;
    }
    
    long rep = b/g;
    long bdivg = 0;
    for(int i=0;i<64;++i){
      if(((rep>>i)&1)==1)bdivg = (bdivg*bekiten2[i]%mod + bekione2[i])%mod;
    }
    System.out.println((onea*bdivg)%mod);
  }
}