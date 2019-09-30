using System ;
namespace Main{
 class Program{
  static void Main(string[] args){
   int N = 2 * int.Parse(Console.ReadLine());
    string []buff = Console.ReadLine().Split(' ');
    int []a = new int[N];
    for ( int i= 0 ; i< N  ;i++)
      a[i] = int.Parse(buff[i]);
    
    for ( int i = 0 ; i < N -1  ; i++){
      for ( int j = i+1 ; j < N ;j++){
        if( a[i] > a[j]){
         int swap = a[i];
          a[i] = a[j];
          a[j] = swap;
        }
      }
    }
    int sum = 0;
    for ( int i = 0 ; i < N / 2  ;i++){
      sum += min(a[2 * i],a[2 * i+1]); 
    }
    Console.WriteLine(sum);
  }
   static int min(int a , int b){
    return a < b ? a : b  ;
   }
 }
}